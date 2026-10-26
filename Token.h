#include <iostream>
using namespace std;

#ifndef TOKEN_H
#define TOKEN_H
enum class TokenType{
    INTEGAR, PLUS, MINUS, MULTIPLY, DIVIDE, LEFT_PAREN, RIGHT_PAREN
}; //Haven't done it like this before so double check that this shit ain't fucked


struct Token{ //Add helper maybe?
    TokenType type;
    int value;


};
#endif