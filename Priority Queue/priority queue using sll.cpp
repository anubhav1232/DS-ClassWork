#include<iostream>
using namespace std;

class pq_sll {
    struct node {
        int priority;
        int value;
        struct node *next;
    };
    struct node *Front;
    struct node *new_node;
    struct node *ptr;
    struct node *Rear;
    struct node *temp;
    struct node *copy_;
    int count;
    int pr;
public:
    pq_sll() {
        Front = NULL;
        Rear = NULL;
        count = 0;
        pr = 0;
    }
    void enqueue(int num) {
        if (Front == NULL) {
            cout << "enter the priority of first node" << endl;
            new_node = new node;
            cin >> new_node->priority;
            new_node->value = num;
            new_node->next = Front;
            Front = new_node;
            Rear = new_node;
        } else {
            cout << "enter the priority of the node" << endl;
            cin >> pr;
            insert_val(num, pr);
        }
    }
    void insert_beg(int num, int pr) {
        new_node = new node;
        new_node->value = num;
        new_node -> priority = pr;
        new_node->next = Front;
        Front = new_node;
    }
    void insert_end(int num, int pr) {
        new_node = new node;
        new_node->value = num;
        new_node -> priority = pr;
        new_node->next = NULL;
        Rear->next = new_node;
        Rear = new_node;
    }
    void insert_val(int num, int pr) {
        int n = 0;
        ptr = Front;
        temp = ptr;
        while(ptr != NULL){
            if(ptr ->priority > pr){
                n = 1;
                break;
            }
            temp = ptr;
            ptr = ptr -> next;
        }
        if(n == 0){
            insert_end(num, pr);
        }
        else if(ptr == Front){
            insert_beg(num, pr);
        }
        else{
            new_node = new node;
            new_node -> value = num;
            new_node -> priority = pr;
            new_node -> next = ptr;
            temp -> next = new_node;
        }
    }
    void dequeue(){
        if(Front == NULL) {
            cout << "UNDERFLOW" << endl;
        }
        else if(Front == Rear){
            cout << Front -> value << endl;
            Front = NULL;
            Rear = NULL;
        }
        else{
            cout << Front -> value << endl;
            Front = Front->next;
        }
    }
    void dequeue(int pr){
        if(Front == NULL){
            cout << "UNDERFLOW" << endl;
        }
        else{
            ptr = Front;
            temp = Front;
            int n = 0, n1 = 0;
            while (ptr != NULL){
                if(ptr -> priority == pr){
                    n = 1;
                    cout << ptr -> value << " ";
                    temp ->next = ptr ->next;
                    ptr = ptr ->next;
                }
                else{
                    temp = ptr;
                    ptr = ptr -> next;
                }
            }
            if (n == 0){
                cout << "No process with such priority found" << endl;
            }
            cout << endl;
        }
    }
    void pro() {
        char a;
        cout << "Select option" << endl;
        cout << "a to Display all processes in queue" << endl;
        cout << "b to Process all the processes" << endl;
        cin >> a;
        ptr = Front;
        if(a == 'a') {
        	if(Front == NULL){
        		cout << "UNDERFLOW" << endl;
        	}
        	else{
            	while (ptr != NULL) {
                	cout << ptr -> value << " ";
                	ptr = ptr -> next;
            	}
            	cout << endl;
        	}
        }
        else if(a == 'b'){
            while (ptr != NULL) {
                dequeue();
                ptr = ptr -> next;
            }
        }
        else {
            cout << "Enter a valid option" << endl;
        }
    }
};
int main(){
    pq_sll ob1;
    int n , num;
    char a;
    cout << "Welcome to the program for performing operations on priority queue "<< endl;
    cout << "Enter the option for corresponding operation and -1 to terminate the program" << endl;
    cout << "1. Enqueue command" << endl << "2. dequeue command" << endl;
    cout << "3. process all elements" << endl;
    cin >> n;
    while(n != -1){
        switch(n) {
            case 1: {
                cout << "enter the value to enqueue" << endl;
                cin >> num;
                ob1.enqueue(num);
                break;
            }
            case 2: {
                cout << "enter the appropriate choice" << endl;
                cout << "a. dequeue highest priority element" << endl;
                cout << "b. dequeue specific priority element" << endl;
                cin >> a;
                if(a == 'a'){
                    ob1.dequeue();
                }
                else if(a == 'b'){
                    cout << "enter the priority of which you want to process the elements of" << endl;
                    cin >> num;
                    ob1.dequeue(num);
                }
                else{
                    cout << "wrong option try again" << endl;
                }
                break;
            }
            case 3: {
                ob1.pro();
            }
        }
        cout << "Enter the option for corresponding operation and -1 to terminate the program" << endl;
        cout << "1. Enqueue command" << endl << "2. dequeue command" << endl;
        cout << "3. process all elements" << endl;
        cin >> n;
    }
}
