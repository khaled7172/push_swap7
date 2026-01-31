#!/bin/bash

# Quick tests for push_swap

echo "=== QUICK TESTS ==="
echo ""

# Test 1: Simple
echo "Test 1: 3 2 1"
./push_swap --bench 3 2 1 2>&1 | tee /dev/stderr | ./checker_linux 3 2 1
echo ""

# Test 2: Five numbers
echo "Test 2: 5 4 3 2 1"
./push_swap --bench 5 4 3 2 1 2>&1 | tee /dev/stderr | ./checker_linux 5 4 3 2 1
echo ""

# Test 3: Already sorted
echo "Test 3: Already sorted (1 2 3 4 5)"
./push_swap --bench 1 2 3 4 5 2>&1 | tee /dev/stderr | ./checker_linux 1 2 3 4 5
echo ""

# Test 4: Your original test
echo "Test 4: 500 random numbers"
shuf -i 0-9999 -n 500 > args.txt
echo "Running: ./push_swap --bench \$(cat args.txt) 2> bench.txt | ./checker_linux \$(cat args.txt)"
./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)
echo ""
echo "Benchmark output:"
cat bench.txt
echo ""
echo "Total operations:"
./push_swap $(cat args.txt) | wc -l