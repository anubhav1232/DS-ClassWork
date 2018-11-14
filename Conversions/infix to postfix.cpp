#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

char stack_[50];
char postfix[50];
int in = 0;
int top = 0;

int prec(char i){
	if(i == '^')
		return 1;
	else if(i == '*' || i == '/')
		return 2;
	else if(i == '+' || i == '-'){
		return 3;
	}
	return 0;
}

void push(char i)
{
    stack_[top] = i;
    top++;
    
}

void insert_postfix(char i){
    postfix[in] = i;
    cout << postfix[in] << " ";
    in += 1;
}

void pop(){
    insert_postfix(stack_[top]);
    top --;
}
void show(){
	postfix[in] = '\0';
	in = 0;
	while(postfix[in]!= '\0'){
		cout << postfix[in] << " ";
		in+=1;
	}
}

int main()
{
	push('(');
    char infix[50];
    char ch;
    int i = 0;
    cin >> ch;
    while(ch != '&'){
    	infix[i] = ch;
    	cin >> ch;
    	i+=1;
    }
    int index = i+1;
    infix[index] = ')';
    infix[index+1] = '\0';
    i = 0 ;
    while (infix[i]!= '\0'){
        if(isalpha(infix[i]))
            insert_postfix(infix[i]);
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*' || infix[i] == '^')
        {
            if(prec(infix[i]) > prec(stack_[top])){
                push(infix[i]);
            }
            else if(prec(infix[i]) <= prec(stack_[top])){
                while(prec(infix[i]) <= prec(stack_[top])){
					pop();
				}
			}
            push(infix[i]);
        }
        else if(infix[i] == ')'){
        	while(stack_[top]!= '(')
        	{
        		pop();
        	}
        	pop();
        }
        i+=1;
    }
    //show();
}
