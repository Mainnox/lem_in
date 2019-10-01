clear
./tests/generator --flow-ten > tests/result_ten
echo "\n\n----------------------------"
echo "flow = 10"
echo "the result of generator is :"
tail -n 1 tests/result_ten | cut -c 39-
echo "- - - - - - - - - - - - - - "
echo "my result is :"
./lem-in < tests/result_ten | wc -l | cut -c 6-
echo "----------------------------"
