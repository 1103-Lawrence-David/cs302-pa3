#include "LinkedStack.h"
#include "LinkedQueue.h"

LinkedQueue<Token> tokenize(const string& exp){
    LinkedQueue<Token> tokenQueue;
    int length = exp.length();
    int i = 0;

    while(i < length){
        char ch = exp[i];
        
        if(isspace(ch)){
            i++;
        }

        if(isdigit(ch)){
            string numStr = "";
            
            while(i < length && isdigit(exp[i])){
                numStr += exp[i];
                i++;
            }
            
            int intval = stoi(numStr);
            
            tokenQueue.enqueue(Token(TokenType::INTEGAR, intval));
        }

        switch(ch){
            case '+':
                tokenQueue.enqueue(Token(TokenType::PLUS, 0));
            case '-':
                tokenQueue.enqueue(Token(TokenType::MINUS, 0));
            case '*':
                tokenQueue.enqueue(Token(TokenType::MULTIPLY, 0));
            case '/':
                tokenQueue.enqueue(Token(TokenType::DIVIDE, 0));
            case '(':
                tokenQueue.enqueue(Token(TokenType::LEFT_PAREN, 0));
            case ')':
                tokenQueue.enqueue(Token(TokenType::RIGHT_PAREN, 0));
            default:
                cout << "Tokenizer error at position " << i << " unexpected character: " << ch << endl;
        }
    }
    return tokenQueue;
}