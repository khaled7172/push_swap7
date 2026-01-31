#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}  PUSH_SWAP BENCHMARK TESTS${NC}"
echo -e "${BLUE}========================================${NC}\n"

# Test 1: Basic compilation
echo -e "${YELLOW}[TEST 1] Compilation${NC}"
make re > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo -e "${GREEN}✓ Compilation successful${NC}\n"
else
    echo -e "${RED}✗ Compilation failed${NC}\n"
    exit 1
fi

# Test 2: Already sorted (should output OK with 0 operations)
echo -e "${YELLOW}[TEST 2] Already sorted input${NC}"
./push_swap --bench 1 2 3 4 5 2> bench_test.txt | ./checker_linux 1 2 3 4 5
RESULT=$?
echo -e "Benchmark output:"
cat bench_test.txt
if [ $RESULT -eq 0 ]; then
    echo -e "${GREEN}✓ Already sorted test passed${NC}\n"
else
    echo -e "${RED}✗ Already sorted test failed${NC}\n"
fi

# Test 3: Simple 3 numbers
echo -e "${YELLOW}[TEST 3] Three numbers (3 2 1)${NC}"
./push_swap --bench 3 2 1 2> bench_test.txt | ./checker_linux 3 2 1
RESULT=$?
echo -e "Benchmark output:"
cat bench_test.txt
if [ $RESULT -eq 0 ]; then
    echo -e "${GREEN}✓ Three numbers test passed${NC}\n"
else
    echo -e "${RED}✗ Three numbers test failed${NC}\n"
fi

# Test 4: Five numbers
echo -e "${YELLOW}[TEST 4] Five numbers${NC}"
./push_swap --bench 5 4 3 2 1 2> bench_test.txt | ./checker_linux 5 4 3 2 1
RESULT=$?
echo -e "Benchmark output:"
cat bench_test.txt
TOTAL_OPS=$(./push_swap 5 4 3 2 1 | wc -l)
echo -e "Total operations: $TOTAL_OPS"
if [ $RESULT -eq 0 ]; then
    if [ $TOTAL_OPS -le 12 ]; then
        echo -e "${GREEN}✓ Five numbers test passed (≤12 ops)${NC}\n"
    else
        echo -e "${YELLOW}⚠ Five numbers sorted but used $TOTAL_OPS ops (expected ≤12)${NC}\n"
    fi
else
    echo -e "${RED}✗ Five numbers test failed${NC}\n"
fi

# Test 5: 100 random numbers
echo -e "${YELLOW}[TEST 5] 100 random numbers${NC}"
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
./push_swap --bench $ARG 2> bench_test.txt | ./checker_linux $ARG
RESULT=$?
echo -e "Benchmark output:"
cat bench_test.txt
TOTAL_OPS=$(./push_swap $ARG | wc -l)
echo -e "Total operations: $TOTAL_OPS"
if [ $RESULT -eq 0 ]; then
    if [ $TOTAL_OPS -le 700 ]; then
        echo -e "${GREEN}✓ 100 numbers test passed (≤700 ops: EXCELLENT)${NC}\n"
    elif [ $TOTAL_OPS -le 900 ]; then
        echo -e "${GREEN}✓ 100 numbers test passed (≤900 ops: GOOD)${NC}\n"
    elif [ $TOTAL_OPS -le 1100 ]; then
        echo -e "${YELLOW}⚠ 100 numbers sorted but used $TOTAL_OPS ops (≤1100: ACCEPTABLE)${NC}\n"
    elif [ $TOTAL_OPS -le 1500 ]; then
        echo -e "${YELLOW}⚠ 100 numbers sorted but used $TOTAL_OPS ops (≤1500: PASS)${NC}\n"
    else
        echo -e "${RED}✗ 100 numbers used too many ops: $TOTAL_OPS (expected ≤1500)${NC}\n"
    fi
else
    echo -e "${RED}✗ 100 numbers test failed (not sorted correctly)${NC}\n"
fi

# Test 6: 500 random numbers
echo -e "${YELLOW}[TEST 6] 500 random numbers${NC}"
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
./push_swap --bench $ARG 2> bench_test.txt | ./checker_linux $ARG
RESULT=$?
echo -e "Benchmark output:"
cat bench_test.txt
TOTAL_OPS=$(./push_swap $ARG | wc -l)
echo -e "Total operations: $TOTAL_OPS"
if [ $RESULT -eq 0 ]; then
    if [ $TOTAL_OPS -le 5500 ]; then
        echo -e "${GREEN}✓ 500 numbers test passed (≤5500 ops: EXCELLENT)${NC}\n"
    elif [ $TOTAL_OPS -le 7000 ]; then
        echo -e "${GREEN}✓ 500 numbers test passed (≤7000 ops: GOOD)${NC}\n"
    elif [ $TOTAL_OPS -le 8500 ]; then
        echo -e "${YELLOW}⚠ 500 numbers sorted but used $TOTAL_OPS ops (≤8500: ACCEPTABLE)${NC}\n"
    elif [ $TOTAL_OPS -le 11500 ]; then
        echo -e "${YELLOW}⚠ 500 numbers sorted but used $TOTAL_OPS ops (≤11500: PASS)${NC}\n"
    else
        echo -e "${RED}✗ 500 numbers used too many ops: $TOTAL_OPS (expected ≤11500)${NC}\n"
    fi
else
    echo -e "${RED}✗ 500 numbers test failed (not sorted correctly)${NC}\n"
fi

# Test 7: Benchmark format validation
echo -e "${YELLOW}[TEST 7] Benchmark format validation${NC}"
./push_swap --bench 5 4 3 2 1 2> bench_test.txt > /dev/null
if grep -q "Disorder:" bench_test.txt && \
   grep -q "Strategy:" bench_test.txt && \
   grep -q "Total operations:" bench_test.txt && \
   grep -q "sa:" bench_test.txt; then
    echo -e "${GREEN}✓ Benchmark format is correct${NC}\n"
else
    echo -e "${RED}✗ Benchmark format is incorrect${NC}"
    echo -e "Expected format:"
    echo -e "  Disorder: XX.XX%"
    echo -e "  Strategy: <name> / Complexity: O(...)"
    echo -e "  Total operations: X"
    echo -e "  sa: X, sb: X, ...\n"
fi

# Test 8: No benchmark flag (should not output to stderr)
echo -e "${YELLOW}[TEST 8] Without --bench flag (no stderr output)${NC}"
./push_swap 3 2 1 2> bench_test.txt | ./checker_linux 3 2 1
if [ ! -s bench_test.txt ]; then
    echo -e "${GREEN}✓ No benchmark output without --bench flag${NC}\n"
else
    echo -e "${RED}✗ Unexpected stderr output without --bench flag${NC}\n"
fi

# Test 9: Different strategies
echo -e "${YELLOW}[TEST 9] Testing different strategy flags${NC}"

echo -e "  Testing --simple..."
./push_swap --bench --simple 5 4 3 2 1 2> bench_test.txt | ./checker_linux 5 4 3 2 1
if grep -q "simple" bench_test.txt; then
    echo -e "${GREEN}  ✓ Simple strategy works${NC}"
else
    echo -e "${RED}  ✗ Simple strategy failed${NC}"
fi

echo -e "  Testing --medium..."
ARG=$(shuf -i 0-999 -n 50 | tr '\n' ' ')
./push_swap --bench --medium $ARG 2> bench_test.txt | ./checker_linux $ARG
if grep -q "medium" bench_test.txt; then
    echo -e "${GREEN}  ✓ Medium strategy works${NC}"
else
    echo -e "${RED}  ✗ Medium strategy failed${NC}"
fi

echo -e "  Testing --complex..."
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
./push_swap --bench --complex $ARG 2> bench_test.txt | ./checker_linux $ARG
if grep -q "complex" bench_test.txt; then
    echo -e "${GREEN}  ✓ Complex strategy works${NC}\n"
else
    echo -e "${RED}  ✗ Complex strategy failed${NC}\n"
fi

# Test 10: Disorder calculation
echo -e "${YELLOW}[TEST 10] Disorder calculation${NC}"
./push_swap --bench 1 2 3 4 5 2> bench_test.txt > /dev/null
DISORDER=$(grep "Disorder:" bench_test.txt | grep -oE "[0-9]+\.[0-9]+")
echo -e "  Sorted input disorder: $DISORDER%"
if (( $(echo "$DISORDER < 10" | bc -l) )); then
    echo -e "${GREEN}  ✓ Low disorder for sorted input${NC}"
else
    echo -e "${YELLOW}  ⚠ Expected disorder < 10% for sorted input${NC}"
fi

./push_swap --bench 5 4 3 2 1 2> bench_test.txt > /dev/null
DISORDER=$(grep "Disorder:" bench_test.txt | grep -oE "[0-9]+\.[0-9]+")
echo -e "  Reverse sorted disorder: $DISORDER%"
if (( $(echo "$DISORDER > 80" | bc -l) )); then
    echo -e "${GREEN}  ✓ High disorder for reverse sorted input${NC}\n"
else
    echo -e "${YELLOW}  ⚠ Expected disorder > 80% for reverse sorted input${NC}\n"
fi

# Cleanup
rm -f bench_test.txt

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}  ALL TESTS COMPLETED${NC}"
echo -e "${BLUE}========================================${NC}"