clear
./tests/generator --flow-thousand > tests/result_thousand
echo "\n\n----------------------------"
echo "flow = 1000"
echo "the result of generator is :"
tail -n 1 tests/result_thousand | cut -c 39-
echo "- - - - - - - - - - - - - - "
echo "my result is :"
./lem-in < tests/result_thousand | wc -l | cut -c 6-
echo "----------------------------"
