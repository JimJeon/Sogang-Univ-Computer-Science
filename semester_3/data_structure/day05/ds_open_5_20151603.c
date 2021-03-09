#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef enum {lparen, rparen, plus, minus, multiple, divide,
    modula, assignment, operand, space} precedence;

bool Input(const char*, char*);
bool Prefix(char*, const char*);
bool Postfix(char*, const char*);
bool Print(const char*, const char*);
void StrReverse(char*, const char*);
precedence GetToken(char symbol);


int main(void) {
    // initialized
    char expression[1111] = {0, };
    char result[1111] = {0, };

    if(!Input("a.txt", expression)) {
        fprintf(stderr, "Error: file open error\n");
        exit(EXIT_FAILURE);
    }

    // infix to prefix conversion
    if(!Prefix(result, expression)) {
        fprintf(stderr, "Error: invalid parenthesis\n");
        exit(EXIT_FAILURE);
    }

    Print("b.txt", result);

    // infix to postfix conversion
    if(!Postfix(result, expression)) {
        fprintf(stderr, "Error: invalid parenthesis\n");
        exit(EXIT_FAILURE);
    }

    Print("c.txt", result);

    exit(EXIT_SUCCESS);
}
bool Input(const char* filename, char* destination) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) return false;
    fscanf(fp, "%s", destination);
    return true;
}
bool Prefix(char* destination, const char* expression) {
    // initialized
    int s_idx = 0;
    int d_idx = 0;
    int top = -1;
    int paren_flag = 0;
    char stack[1111] = {0, };
    char source[1111] = {0, };
    // not initialized
    int p_value;
    char token;

    // precedence
    int isp[] = {  19, 0, 12, 12, 13, 13, 13, 0 }; // in-stack precedence
    int icp[] = { 19, 20, 12, 12, 13, 13, 13, 0 }; // incoming precedence

    StrReverse(source, expression);

    do {
        token = source[s_idx++];
        if(token == '\0') break;

        p_value = GetToken(token);

        if(p_value == space) continue;
        if(p_value == operand) {
            destination[d_idx++] = token;
            continue;
        }
        if(p_value == rparen) paren_flag++;

        if(top == -1) stack[++top] = token;
        else if( p_value == lparen ) {
            if( !paren_flag ) return false;
            while( GetToken(stack[top]) != rparen )
                destination[d_idx++] = stack[top--];
            top -= 1;
        }
        else if( isp[GetToken(stack[top])] <= icp[p_value] )
            stack[++top] = token;
        else
            while( isp[GetToken(stack[top])] > icp[p_value] )
                destination[d_idx++] = stack[top--];
    } while(true);

    while(top != -1) destination[d_idx++] = stack[top--];

    StrReverse(destination, destination);

    return true;
}
bool Postfix(char* destination, const char* source) {
    // initialized
    int s_idx = 0;
    int d_idx = 0;
    int top = -1;
    int paren_flag = 0;
    char stack[1111] = {0, };
    // not initialized
    int p_value;
    char token;

    // precedence
    int isp[] = {  0, 19, 12, 12, 13, 13, 13, 0 }; // in-stack precedence
    int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 }; // incoming precedence

    do {
        token = source[s_idx++];
        if(token == '\0') break;

        p_value = GetToken(token);

        if(p_value == space) continue;
        if(p_value == operand) {
            destination[d_idx++] = token;
            continue;
        }
        if(p_value == lparen) paren_flag++;

        if(top == -1) stack[++top] = token;
        else if( p_value == rparen ) {
            if( !paren_flag ) return false;
            while( GetToken(stack[top]) != lparen )
                destination[d_idx++] = stack[top--];
            top -= 1;
        }
        else if( isp[GetToken(stack[top])] < icp[p_value] )
            stack[++top] = token;
        else
            while( isp[GetToken(stack[top])] >= icp[p_value] )
                destination[d_idx++] = stack[top--];
    } while(true);

    while(top != -1) destination[d_idx++] = stack[top--];

    return true;
}
bool Print(const char* filename, const char* target) {
    FILE* fp = fopen(filename, "a");
    if(fp == NULL) return false;
    fprintf(fp, "%s\n", target);
    return true;
}
precedence GetToken(char symbol) {
    if( ('A'<=symbol && symbol<='Z')
     || ('a'<=symbol && symbol<='z'))
            symbol = 'a';

    switch(symbol) {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '*': return multiple;
        case '/': return divide;
        case '%': return modula;
        case '=': return assignment;
        case 'a': return operand;
        case ' ': return space;
        default : 
            fprintf(stderr, "Error: invalid precedence found\n");
            exit(EXIT_FAILURE);
    }
}
void StrReverse(char* destination, const char* source) {
    int i = 0;
    int length = strlen(source);
    char *tmp_str = calloc(length + 1, sizeof(*tmp_str));
    tmp_str[length] = '\0';
    for( i = 0;i < length; ++i)
        tmp_str[length - i - 1] = source[i];
    strcpy(destination, tmp_str);
    free(tmp_str);
}
