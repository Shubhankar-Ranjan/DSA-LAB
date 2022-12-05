#include<stdio.h>
#include<stdlib.h>      // for exit() 
#include<ctype.h>     // for isdigit(char ) 
#include<string.h>

#define N 100
char stack[N];
int top = -1;

//push
void Push(char item){
    if(top == N-1){
        printf("Overflow");
    }
    else{
        top++;
        stack[top] = item;
    }
}

//pop
char Pop(){
    char item;
    if(top == -1){
        printf("Underflow");
    }
    else{
        item = stack[top];
        top--;
        return item;
    }
}


int precedence(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else {
        return 0;
    }
}

void infixtoPostfix(char s[]){

    int j=0,x;
    char res[j];

    for (int i = 0; i < strlen(s); i++)
    {
        
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res[j++] += s[i];
        }
        else if(s[i]=='('){
            Push(s[i]);
        }
        else if(s[i]==')'){
             x = Pop();                   
			while(x != '(')              
			{
				res[j++] += x;
				x = Pop();
			}
        }
        else{
            while (precedence(stack[top])>precedence(s[i]))
            {
                res[j++] += stack[top];
                Pop();
            }
            Push(s[i]);
        }
    }
    res[j] = '\0';
    printf("%s",res[j]); 
}

int main(){

    infixtoPostfix("a+b*(c^d-e)^(f+g*h)-i");
    return 0;
}