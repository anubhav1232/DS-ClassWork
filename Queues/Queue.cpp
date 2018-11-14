#include <iostream>
using namespace std;

// queue is a data structure. which stores collection of data with a restriction/constraint
// insertion from one end known as rear/tail.
// data can be removed from other end known as front/head.
// complexity of a queue is O(1)

class queue{
    int top;
    int ele;
    int front;
    int back;
    int * arr;
    int num;
public:
    queue()
    {
        cout << "constructor, enter the size of queue" << endl;
        cin >> ele;
        arr = new int(ele);
        front = -1;
        back = -1;
    }
    void Enqueue(){
        if(front < 0 && back < 0){
            cout << "Enter the first element of queue" << endl;
            cin >> num;
            front ++;
            back ++;
            arr[back] = num;
            back ++;
        }
        else if(back == ele){
            cout << "Queue is full" << endl;
        }
        else {
            cout << "enter the element to push" << endl;
            cin >> num;
            arr[back] = num;
            back ++;
        }
    }
    void Dequeue(){
        if(back < 0){
            cout << "Queue is Empty" << endl;
        }
        else if(front == back) {
            cout << arr[front] << endl;
            back = -1;
            front = -1;
            cout << "deleting the only remaining element" << endl;
            cout << "No element remains" << endl;
        }
        else{
            cout << arr[front] << endl;
            front ++;
        }
    }
    void is_empty(){
        if(front == -1 && back == -1){
            cout << "TRUE" << endl;
        }
        else{
            cout << "FALSE" << endl;
        }
    }
    void size(){
        cout << back-front;
    }
    void is_full(){
        if(back == ele-1)
            cout << "queue is full" << endl;
        else
            cout << "Queue not full" << endl;
    }
    void display(){
    	if(front < 0){
            cout << endl << "underflow" << endl;
        }
        while(front > -1){
            Dequeue();
        }
    	cout << endl << "displayed all elements" << endl;
    }
};
int main()
{
    queue s1;
    int n;
    cout << "this program is for queue insertion and deletion" << endl;
    cout << "1. enqueue command" << endl << "2. dequeue command" << endl;
    cout << "3. check if empty" << endl <<"4. to check if queue is full" << endl;
    cout << "5. size of queue" << endl << "6. to display current queue " << endl;
    cout << "enter -1 to exit program" << endl;
    cin >> n;
    while(n!=-1) {
        switch (n) {
            case 1: {
                s1.Enqueue();
                break;
            }
            case 2: {
                s1.Dequeue();
                break;
            }
            case 3: {
                s1.is_empty();
                break;
            }
            case 4: {
                s1.is_full();
                break;
            }
            case 5: {
                s1.size();
                break;
            }
            case 6: {
            	s1.display();
            	break;
            }
            default: {
                cout << "invalid input" << endl;
            }
        }
        cout << "1. enqueue command" << endl << "2. dequeue command" << endl;
        cout << "3. check if empty" << endl << "4. to check if queue is full" << endl;
		cout << "5. size of queue" << endl <<"6. to display current queue " << endl;
        cout << "enter -1 to exit program" << endl;
        cin >> n;
    }
}
