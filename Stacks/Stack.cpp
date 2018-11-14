#include <iostream>
using namespace std;

class stack{
    int top;
    int *arr;
    int num;
    int ele;
public:
    stack()
    {
        cout << "Enter stack size" << endl;
        cin >> ele;
        arr = new int(ele);
        top = -1;
    }
    void push(){
        if(top >= ele){
            cout << "OVERFLOW" << endl;
        }
        else {
            cout << "enter the element to push" << endl;
            top += 1;
            cin >> num;
            arr[top] = num;
        }
    }
    void pop(){
        if(top < 0){
            cout << "UNDERFLOW" << endl;
        }
        else{
            cout << arr[top] << endl;
            top-=1;
        }
    }
    void is_empty(){
        if(top<0){
            cout << "TRUE" << endl;
        }
        else{
            cout << "FALSE" << endl;
        }
    }
    void peek(){
        if(top < 0){
            cout << "Empty" << endl;
        }
        else {
            cout << arr[top] << endl;
        }
    }
};
int main()
{
    stack s1;
    int n;
    cout << "this program is for stack insertion and deletion" << endl;
    cout << "1. for pushing element" << endl << "2. for popping element" << endl;
    cout << "3. check if empty" << endl <<"4. peeking the top element" << endl;
    cout << "enter -1 to exit program" << endl;
    cin >> n;
    while(n!=-1) {
        switch (n) {
            case 1: {
                s1.push();
                break;
            }
            case 2: {
                s1.pop();
                break;
            }
            case 3: {
                s1.is_empty();
                break;
            }
            case 4: {
                s1.peek();
                break;
            }
            default: {
                cout << "invalid input" << endl;
            }
        }
        cout << "1. for pushing element" << endl << "2. for popping element" << endl;
    	cout << "3. check if empty" << endl << "4. peeking the top element" << endl;
    	cout << "enter -1 to exit program" << endl;
        cin >> n;
    }
}
