commands:

make: compiles the program. 

./execute : runs the program. No external files required (no txts, etc.). Compiles and runs on linux subsystem for windows in ubuntu on vscode. 

make clean: clears the files to allow recompilation.

limitations: When a single number is input, it does not return any errors and outputs the number. If this is intended to produce an error, this is not possible in this program. In addition, not all error checking is properly implemented or implemented at all. 

LinkedStack::push: O(1). There are no loops, so it executes in constant time.

LinkedStack::pop: O(1). No loops, executes in constant time.

LinkedQueue::enqueue: O(1). No loops, in constant time.

linkedqueue::dequeue: O(1). Executes in constant time.

tokenization: The worst case is O(n^2). while there are 3 while loop, only two nested while loops can run for each input, assuming the input triggers the second or third while loop. This means it is O(n^2)

infix to postfix:The worst case is again O(n^2). While there are a significant amount of while loops, only two nested while loops can be run at one time. This gives O(n^2).

postfix eval: The worst case is O(n). there is a single while loop, which gives us O(n).