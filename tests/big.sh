clear
./tests/generator --big > tests/result_big
echo "\n\n----------------------------"
echo "flow = ? - big"
echo "the result of generator is :"
tail -n 1 tests/result_big | cut -c 39-
echo "- - - - - - - - - - - - - - "
echo "my result is :"
./lem-in < tests/result_big | wc -l | cut -c 6-
echo "----------------------------"
