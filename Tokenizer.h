#include "LinkedStack.h"
#include "LinkedQueue.h"
int precedence(const Token& t){
    if(t.type == TokenType::PLUS || t.type == TokenType::MINUS){
        return 1;
    }
    if(t.type == TokenType::MULTIPLY || t.type == TokenType:: DIVIDE){
        return 2;
    }
    return 0;
}

bool isOperator(const Token& token){
    return token.type == TokenType::PLUS || token.type == TokenType::MINUS ||
           token.type == TokenType::MULTIPLY || token.type == TokenType::DIVIDE;
}

LinkedQueue<Token> tokenize(const string& exp, bool& err){
    LinkedQueue<Token> tokenQueue;
    int length = exp.length();
    int i = 0;

    if(length == 0){
        cout << "Error: Empty input expression" << endl;
        err = true;
        return tokenQueue;
    }

    cout << "Tokens: ";
    while(i < length){
        
        if(isspace(exp[i])){
           while(i < length && isspace(exp[i])){
                i++;
           }
        }

        else if(isdigit(exp[i])){
            string numStr = "";
            
            while(i < length && isdigit(exp[i])){
                numStr += exp[i];
                i++;
            }
            
            int intval = stoi(numStr);
            cout << intval;
            tokenQueue.enqueue(Token(TokenType::INTEGAR, intval));
        }
        else{
            switch(exp[i]){
                case '+':
                    tokenQueue.enqueue(Token(TokenType::PLUS, 0));
                    cout << exp[i];
                    break;
                case '-':
                    tokenQueue.enqueue(Token(TokenType::MINUS, 0));
                    cout << exp[i];
                    break;   
                case '*':
                    tokenQueue.enqueue(Token(TokenType::MULTIPLY, 0));
                    cout << exp[i];
                    break;
                case '/':
                    tokenQueue.enqueue(Token(TokenType::DIVIDE, 0));
                    cout << exp[i];
                    break;
                case '(':
                    tokenQueue.enqueue(Token(TokenType::LEFT_PAREN, 0));
                    cout << exp[i];
                    break;    
                case ')':
                    tokenQueue.enqueue(Token(TokenType::RIGHT_PAREN, 0));
                    cout << exp[i];
                    break;    
                default:
                    cout << "Tokenizer error at position " << i << " unexpected character: " << exp[i] << endl;
                    err = true;
                    break;
            }
            i++;
        }
        
    }
    cout << endl;
    return tokenQueue;
}

LinkedQueue<Token> toPostfix(const LinkedQueue<Token>& infix, bool& err) {
    LinkedQueue<Token> postfixQueue;
    LinkedStack<Token> opStack;
    LinkedQueue<Token> infixcopy = infix;
     Token last;

    while(!infixcopy.isEmpty()){
        Token current = infixcopy.dequeue();

        if(current.type == TokenType::INTEGAR){
            postfixQueue.enqueue(current);
        } 
        else if(current.type == TokenType::LEFT_PAREN){
            opStack.push(current);
        } 
        else if(current.type == TokenType::RIGHT_PAREN){
            bool foundMatch = false;
            while(!opStack.isEmpty()){
                Token top = opStack.pop();

                if(top.type == TokenType::LEFT_PAREN){
                    foundMatch = true;
                    break;
                }

                postfixQueue.enqueue(top);
            }
            if(!foundMatch){
                cout << "mismatched parenthesis: missing left" << endl;
                err = true;
                return postfixQueue;
            }
        } 
        else if(isOperator(current)){
            LinkedStack<Token> tempStack;

            while(!opStack.isEmpty()){
             Token top = opStack.pop();
             
             if(isOperator(top) && precedence(top) >= precedence(current)){
                postfixQueue.enqueue(top);
             }
             else{
                opStack.push(top);
                break;
             }
            }
            opStack.push(current);
        }
        last = current;
    }

    if(isOperator(last)){
        cout << "Error: can't end with operator" << endl;
        err = true;
        return postfixQueue;
    }

    while(!opStack.isEmpty()){
        Token top = opStack.pop();
        if(top.type == TokenType::LEFT_PAREN || top.type == TokenType::RIGHT_PAREN){
            cout << "Mismatched parenthesis: missing right" << endl;
            err = true;
            return postfixQueue;
        }
        postfixQueue.enqueue(top);
    }

    LinkedQueue<Token> printQueue = postfixQueue;
    cout << "Postfix: ";
    while(!printQueue.isEmpty()){
        Token temp = printQueue.dequeue();
        if(temp.type == TokenType::INTEGAR){
            cout << temp.value << " ";
        }
        else{
            switch (temp.type){
                case TokenType::PLUS:
                    cout << "+ ";
                    break;
                case TokenType::MINUS:
                    cout << "- ";
                    break;
                case TokenType::MULTIPLY:
                    cout << "* ";
                    break;
                case TokenType::DIVIDE:
                    cout << "/ ";
                    break;
                default:
                    cout << "error with printing";
                    break;
            }
        }
    }
    cout << endl;
    return postfixQueue;
}


int evaluatePostfix(LinkedQueue<Token> postfix, bool& err){
    LinkedStack<int> operands;
    
    while(!postfix.isEmpty()){
        Token current = postfix.dequeue();

        if(current.type == TokenType::INTEGAR){
            operands.push(current.value);
        }
        else if(isOperator(current)){
            if(operands.isEmpty()){
                cout << "Error: no operands found" << endl;
                err = true;
                return 0;
            }
            int right = operands.pop();

            if(operands.isEmpty()){
                cout << "Error: missing operand" << endl;
                err = true;
                return 0;
            }
            int left = operands.pop();

            switch(current.type){
                case TokenType::PLUS:
                    operands.push(left+right);
                    break;
                case TokenType::MINUS:
                    operands.push(left-right);
                    break;
                case TokenType::MULTIPLY:
                    operands.push(left*right);
                    break;
                case TokenType::DIVIDE:
                    if(right == 0){
                        cout << "error: divide by zero!" << endl;
                        err = true;
                        return 0;
                    }
                    operands.push(left/right);
                    break;
                default:
                    cout << "unknown error" << endl;
                    err = true;
                    break;
            }
        }
    }

    if(operands.isEmpty()){
        cout << "error: empty stack at evaluation stage" << endl;
        err = true;
        return 0;
    }
    int final = operands.pop();

    if(!operands.isEmpty()){
        cout << "error: extra operands found" << endl;
        err = true;
        return 0;
    }

    return final;
}