clear
./tests/generator --big-superposition > tests/result_big_sup
echo "\n\n----------------------------"
echo "BIG SUP"
echo "the result of generator is :"
tail -n 1 tests/result_big_sup | cut -c 39-
echo "- - - - - - - - - - - - - - "
echo "my result is :"
./lem-in < tests/result_big_sup | wc -l | cut -c 6-
echo "----------------------------"
