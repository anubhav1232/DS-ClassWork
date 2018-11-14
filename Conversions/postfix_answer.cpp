#include<iostream>
#include<math.h>
using namespace std;
int stack_[50];
char postfix[50];
int top=-1,a=0;
void push(int res)
{
    top++;
    stack_[top]=res;
}
int pop()
{
    a=stack_[top];
    top--;
    return a;
}
int main()
{
    cout<<"Enter the postfix " << endl;
    char ch,res;
    int i=0;
    cin>>ch;
    while(ch!='$')
    {
        postfix[i]=ch;
        cin>>ch;
        i++;
    }
    postfix[i]='\0';
    i=0;
    while(postfix[i]!='\0')
    {
        if(isdigit(postfix[i]))
        {
            res=postfix[i]-48;
        }
        else
        {
            int a=pop();
            int b=pop();
            switch(postfix[i])
            {
                case '^':
                { res=pow(b,a); break; }
                case '*':
                { res=b*a; break; }
                case '/':
                { res=b/a; break; }
                case '+':
                { res=b+a; break; }
                case '-':
                { res=b-a; break; }
            }
        }
        push(res);
        i++;
    }
    cout<<stack_[top];
}
