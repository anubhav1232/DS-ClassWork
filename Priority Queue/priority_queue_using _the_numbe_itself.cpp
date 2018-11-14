#include <iostream>
using namespace std;

class p_queue{
    int save;
    int ele;
    int front;
    int rear;
    int temp;
    int * arr;
    int num;
    int num2;
public:
    p_queue()
    {
        cout << "constructor, enter the size of p_queue" << endl;
        cin >> ele;
        arr = new int(ele);
        front = -1;
        rear = -1;
    }
    void Enqueue(){
        if(front < 0 && rear < 0){
            cout << "Enter the first element of p_queue" << endl;
            cin >> num;
            front ++;
            rear ++;
            arr[rear] = num;
        }
        else if(rear == ele){
            cout << "p_queue is full" << endl;
        }
        else {
            cout << "enter the element to push" << endl;
            cin >> num;
            rear ++;
            num2 = insertion_sort(num);
            arr[rear] = num2;
        }
    }
    void Dequeue(){
        if(rear < 0){
            cout << "p_queue is Empty" << endl;
        }
        else if(front == rear) {
            rear = -1;
            front = -1;
            cout << "deleting the only remaining element" << endl;
            cout << "No element remains" << endl;
        }
        else{
            front ++;
        }
    }
    void is_empty(){
        if(front == -1 && rear == -1){
            cout << "TRUE" << endl;
        }
        else{
            cout << "FALSE" << endl;
        }
    }
    void size(){
        cout << rear-front;
    }
    void is_full(){
        if(rear == ele-1)
            cout << "p_queue is full" << endl;
        else
            cout << "p_queue not full" << endl;
    }
    int insertion_sort(int num){
        temp = rear - 1;
        do{
            if(arr[temp] >= num){
                return num;
            }
            else if(arr[temp] < num){
                save = arr[temp];
                arr[temp] = num;
                num = temp;
                temp --;
            }
        }while(temp>front);
        return num;
    }
    void display(){
        for(int i= front; i < rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl << "displayed all elements" << endl;
    }
};
int main()
{
    p_queue s1;
    int n;
    cout << "this program is for p_queue insertion and deletion" << endl;
    cout << "1. enqueue command" << endl << "2. dequeue command" << endl;
    cout << "3. check if empty" << endl <<"4. to check if p_queue is full" << endl;
    cout << "5. size of p_queue" << endl;//<< "6. to display curent p_queue " << endl;
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
                /*case 6: {
                    s1.display();
                    break;
                }*/
            default: {
                cout << "invalid input" << endl;
            }
        }
        cout << "1. enqueue command" << endl << "2. dequeue command" << endl;
        cout << "3. check if empty" << endl << "4. to check if p_queue is full" << endl;
        cout << "5. size of p_queue" << endl;// <<"6. to display curent p_queue " << endl;
        cout << "enter -1 to exit program" << endl;
        cin >> n;
    }
}
