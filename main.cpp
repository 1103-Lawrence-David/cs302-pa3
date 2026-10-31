#include "Tokenizer.h"

int main(){
    bool err = false;
    string userIn;
    int final;

    while(userIn != "quit"){
        err = false;
        cout << "please enter your expression: ";
        getline(cin, userIn);
        if(userIn == "quit"){
            break;
        }
        cout << "Expression: " << userIn << endl;
        LinkedQueue<Token> tempQ = tokenize(userIn, err);
        if(!err){
            tempQ = toPostfix(tempQ, err);
        }
        if(!err){
            final = evaluatePostfix(tempQ, err);
        }
        if(!err){
            cout << final << endl;
        }
        if(err){
            tempQ.clear();
        }
    }
    return 0;
}