//postfix expression using stack
#include<stdio.h>
#include "Stack.h"
int power(int a,int n){
    if(n==0){
        return 1;
    }
    else{
        int p=power(a,n/2);
        if(n%2==0){
            return p*p;
        }
        else{
            return p*p*a;
        }
    }
}
int evaluation(int a,int b,char op){
    switch(op){
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
        case '%':return a%b;
        case '^':return power(a,b);
    }
}
int postfixevaluation(char postfix[]){
    struct stack s;
    int i=0,a,b,answer,value;
    int symbol;
    initialize(&s);
    while(postfix[i]!='\0'){
        symbol=postfix[i];
        i++;
        if(symbol>='0' && symbol<='9'){
            push(&s,symbol-'0');
        }
        else{
            b=pop(&s);
            a=pop(&s);
            value=evaluation(a,b,symbol);
            push(&s,value);
        }
    }
    answer=stacktop(&s);
    return answer;
}
int main(){
    char postfix[50];
    int y;
    printf("enter the postfix expression");
    scanf("%s",postfix);
    y=postfixevaluation(postfix);
    printf("%d",y);
}