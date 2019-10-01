clear
./tests/generator --flow-one > tests/result_one
echo "\n\n----------------------------"
echo "flow = 1"
echo "the result of generator is :"
tail -n 1 tests/result_one | cut -c 39-
echo "- - - - - - - - - - - - - - "
echo "my result is :"
./lem-in < tests/result_one | wc -l | cut -c 6-
echo "----------------------------"
