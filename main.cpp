#include "Tokenizer.h"

int main(){

    string userIn;

    while(userIn != "quit"){
        cout << "please enter your expression: ";
        getline(cin, userIn);
        if(userIn == "quit"){
            break;
        }
        LinkedQueue<Token> tempQ = tokenize(userIn);
        tempQ = toPostfix(tempQ);
        int final = evaluatePostfix(tempQ);
        cout << final << endl;
    }

    return 0;
}