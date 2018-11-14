#include <iostream>
using namespace std;

// queue is a data structure. which stores collection of data with a restriction/constraint
// queue on dequeue results in empty spaces with increment of front.
// therefore the concept of circular queue is introduced.

class Cqueue{
    int top;
    int ele;
    int front;
    int back;
    int * arr;
    int num;
public:
    Cqueue()
    {
        cout << endl << "constructor, enter the size of Cqueue" << endl;
        cin >> ele;
        arr = new int(ele);
        front = -1;
        back = -1;
    }
    void Enqueue(){
        if(front < 0){
            cout << endl << "Enter the first element of Cqueue" << endl;
            cin >> num;
            front ++;
            back ++;
            arr[back] = num;
        }
        //else if((back + 1)%ele == front)
          else if(front == back + 1 || (front == 0 && back == ele -1)){
            cout << endl << "Cqueue is full" << endl;
        }
        else {
            cout << endl << "enter the element to push" << endl;
            cin >> num;
            if(front != 0 && back == ele -1){
                back = 0;
            }
            else
                back ++;
            //back = (back+1)%ele;
            arr[back] = num;
        }
    }
    void Dequeue(){
        if(back < 0){
            cout << endl << "Cqueue is Empty" << endl;
        }
        else if(front == back) {
            back = -1;
            cout << "deleting the only remaining element " << arr[front];
            front = -1;
            cout << "No element remains" << endl;
        }
        else{
        	cout << endl << "element deleted: " << arr[front] << endl;
            if(front == ele - 1)
                front = 0;
            else
                front ++;
            //front = (front+1) % ele;
        }
    }
    void is_empty(){
        if(front == -1 && back == -1){
            cout << endl << "Cqueue is empty" << endl;
        }
        else{
            cout << endl << "Cqueue is not empty" << endl;
        }
    }
    void size(){
        if(front == -1)
            cout << endl << "empty" << endl;
        else if(front < back)
            cout << endl << (back - front) + 1 << endl;
        else if(back < front)
            cout << endl << (front - back) + 1 << endl;
        else
            cout << endl << "1" << endl;
    }
    void is_full(){
        //if((back + 1)%ele == front)
        if(front == back + 1 || (front == 0 && back == ele -1))
            cout << endl << "Cqueue is full" << endl;
        else
            cout << endl << "Cqueue not full" << endl;
    }
    void display(){
        int i;
        //cout << back << " " << front;
        if(back < front) {
            i = front;
            do{
                cout << arr[i] << " ";
                i++;
                if(i == ele)
                    i = 0;
            }while(i != back);
            cout << arr[i] << endl;
        }
        else{
            for(i = front; i != back; i++){
                cout << arr[i] << " ";
            }
            cout << arr[i] << endl;
        }
        cout << endl << "displayed all elements" << endl;
    }
};
int main()
{
    Cqueue s1;
    int n;
    cout << endl;
    cout << "this program is for Cqueue insertion and deletion" << endl;
    cout << "1. enqueue command" << endl << "2. dequeue command" << endl;
    cout << "3. check if empty" << endl << "4. to check if Cqueue is full" << endl;
    cout << "5. size of Cqueue" << endl << "6. to display current Cqueue " << endl;
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
        cout << endl;
        cout << "1. enqueue command" << endl << "2. dequeue command" << endl;
        cout << "3. check if empty" << endl << "4. to check if Cqueue is full" << endl;
        cout << "5. size of Cqueue" << endl << "6. to display current Cqueue " << endl;
        cout << "enter -1 to exit program" << endl;
        cin >> n;
    }
}
