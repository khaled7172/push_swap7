#!/bin/bash

# Push_swap comprehensive test suite
# Tests parsing, edge cases, and validates output

PROGRAM="./push_swap"
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo "========================================="
echo "PUSH_SWAP COMPREHENSIVE TEST SUITE"
echo "========================================="
echo ""

# Function to run test
run_test() {
    local description="$1"
    local cmd="$2"
    local should_output="$3"  # "yes" or "no"
    local should_error="$4"   # "yes" or "no"
    
    echo -n "Test: $description ... "
    
    output=$(eval "$cmd" 2>&1)
    exit_code=$?
    
    if [ "$should_error" = "yes" ]; then
        if [ $exit_code -ne 0 ] && echo "$output" | grep -q "Error"; then
            echo -e "${GREEN}PASS${NC} (error as expected)"
            return 0
        else
            echo -e "${RED}FAIL${NC} (expected error)"
            echo "  Output: $output"
            echo "  Exit code: $exit_code"
            return 1
        fi
    fi
    
    if [ "$should_output" = "yes" ]; then
        if [ -n "$output" ] && [ $exit_code -eq 0 ]; then
            echo -e "${GREEN}PASS${NC}"
            echo "  Instructions: $(echo "$output" | wc -l) lines"
            return 0
        else
            echo -e "${RED}FAIL${NC} (expected output)"
            echo "  Output: $output"
            echo "  Exit code: $exit_code"
            return 1
        fi
    else
        if [ -z "$output" ] && [ $exit_code -eq 0 ]; then
            echo -e "${GREEN}PASS${NC} (no output, already sorted)"
            return 0
        else
            echo -e "${RED}FAIL${NC} (expected no output)"
            echo "  Output: $output"
            echo "  Exit code: $exit_code"
            return 1
        fi
    fi
}

echo "========================================="
echo "BASIC TESTS"
echo "========================================="

run_test "Single number" "$PROGRAM 42" "no" "no"
run_test "Two sorted" "$PROGRAM 1 2" "no" "no"
run_test "Two unsorted" "$PROGRAM 2 1" "yes" "no"
run_test "Three sorted" "$PROGRAM 1 2 3" "no" "no"
run_test "Three reverse" "$PROGRAM 3 2 1" "yes" "no"
run_test "Three mixed 1" "$PROGRAM 2 1 3" "yes" "no"
run_test "Three mixed 2" "$PROGRAM 3 1 2" "yes" "no"

echo ""
echo "========================================="
echo "QUOTED STRING ARGUMENTS (YOUR ISSUE)"
echo "========================================="

run_test "String arg sorted" "$PROGRAM '1 2' 3 '4 5'" "no" "no"
run_test "String arg unsorted 1" "$PROGRAM '5 4' 3 '2 1'" "yes" "no"
run_test "String arg unsorted 2" "$PROGRAM '2 1' 3" "yes" "no"
run_test "String arg mixed" "$PROGRAM '3 1' 2 '5 4'" "yes" "no"
run_test "Single string" "$PROGRAM '5 4 3 2 1'" "yes" "no"
run_test "Multiple spaces" "$PROGRAM '1  2   3'" "no" "no"

echo ""
echo "========================================="
echo "NEGATIVE NUMBERS"
echo "========================================="

run_test "Negatives sorted" "$PROGRAM -5 -2 0 3" "no" "no"
run_test "Negatives unsorted" "$PROGRAM 3 -2 0 -5" "yes" "no"
run_test "All negatives" "$PROGRAM -1 -5 -3 -2" "yes" "no"
run_test "Negative in string" "$PROGRAM '-5 -2' 0 3" "no" "no"
run_test "Mixed neg/pos unsorted" "$PROGRAM 5 -3 0 -1 2" "yes" "no"

echo ""
echo "========================================="
echo "LARGER SETS (5+ numbers)"
echo "========================================="

run_test "Five sorted" "$PROGRAM 1 2 3 4 5" "no" "no"
run_test "Five reverse" "$PROGRAM 5 4 3 2 1" "yes" "no"
run_test "Five random" "$PROGRAM 3 5 1 4 2" "yes" "no"
run_test "Ten random" "$PROGRAM 7 2 9 1 5 3 8 4 10 6" "yes" "no"
run_test "100 sorted" "$PROGRAM {1..100}" "no" "no"

echo ""
echo "========================================="
echo "ERROR CASES"
echo "========================================="

run_test "No arguments" "$PROGRAM" "no" "no"
run_test "Duplicate numbers" "$PROGRAM 1 2 3 2" "no" "yes"
run_test "Duplicate in string" "$PROGRAM '1 2 3' 2" "no" "yes"
run_test "Non-numeric" "$PROGRAM 1 a 3" "no" "yes"
run_test "Non-numeric in string" "$PROGRAM '1 abc 3'" "no" "yes"
run_test "Empty string" "$PROGRAM ''" "no" "yes"
run_test "Just spaces" "$PROGRAM '   '" "no" "yes"
run_test "Overflow INT_MAX" "$PROGRAM 2147483648" "no" "yes"
run_test "Overflow INT_MIN" "$PROGRAM -2147483649" "no" "yes"
run_test "Leading zeros ok" "$PROGRAM 001 002 003" "no" "no"
run_test "Plus sign" "$PROGRAM +1 +2 +3" "no" "no"
run_test "Invalid format" "$PROGRAM 1-2" "no" "yes"
run_test "Multiple signs" "$PROGRAM ++1" "no" "yes"
run_test "Sign only" "$PROGRAM '-'" "no" "yes"

echo ""
echo "========================================="
echo "FLAGS TESTS (if you have them)"
echo "========================================="

run_test "Bench flag" "$PROGRAM --bench 5 4 3 2 1 2>&1 | grep -q ." "yes" "no"
run_test "Simple strategy" "$PROGRAM --simple 3 2 1" "yes" "no"
run_test "Invalid flag" "$PROGRAM --invalid 1 2 3" "no" "yes"

echo ""
echo "========================================="
echo "EDGE CASES"
echo "========================================="

run_test "INT_MAX" "$PROGRAM 2147483647" "no" "no"
run_test "INT_MIN" "$PROGRAM -2147483648" "no" "no"
run_test "INT_MIN to INT_MAX" "$PROGRAM -2147483648 0 2147483647" "no" "no"
run_test "Only zeros" "$PROGRAM 0 0 0" "no" "yes"
run_test "Single zero" "$PROGRAM 0" "no" "no"

echo ""
echo "========================================="
echo "SPECIFIC PROBLEMATIC INPUTS"
echo "========================================="

# These often break poorly written push_swap implementations
run_test "Already sorted asc" "$PROGRAM 1 2 3 4 5 6 7 8 9 10" "no" "no"
run_test "Reverse sorted desc" "$PROGRAM 10 9 8 7 6 5 4 3 2 1" "yes" "no"
run_test "Middle element max" "$PROGRAM 1 2 10 3 4" "yes" "no"
run_test "Alternating" "$PROGRAM 1 10 2 9 3 8 4 7 5 6" "yes" "no"

echo ""
echo "========================================="
echo "SUMMARY"
echo "========================================="
echo "Tests complete!"
