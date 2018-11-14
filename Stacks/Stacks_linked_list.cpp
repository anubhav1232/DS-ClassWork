//to create a singly linked list starting from the second node delete all the alternate nodes of it and print it
#include<iostream>
using namespace std;

class ll
{
    struct node
    {
        int value;
        struct node*  next;
    };
    struct node* start;
    struct node* new_node;
    struct node* ptr;
    struct node* save;
    struct node* temp;
    struct node* copy_;
    int count;
public:
    ll()
    {
        start=NULL;
        count = 0;
    }
    void create_ll(int num)
    {
        while(num!=-1)
        {
            new_node = new node;
            new_node->value = num;
            new_node->next = start;
            start = new_node;
            count ++;
            cin >> num;
        }
    }
    void create_ll_back(int num)
    {
        while(num!=-1)
        {
            if(start==NULL)
            {

                new_node = new node;
                new_node->value = num;
                new_node->next = start;
                start = new_node;
                save = new_node;
                count++;
            }
            else
            {
                new_node = new node;
                new_node->value = num;
                new_node->next = NULL;
                save->next = new_node;
                save = new_node;
                count++;
            }
            cin >> num;
        }
    }
    void delete1(){
        ptr = start -> next;
        save = ptr -> next;
        temp = start;
        while(ptr -> next != NULL){
        	if (count%2==0) {
            	if (ptr->next != NULL) {
                	temp -> next = save;
                	ptr = NULL;
                	temp = save;
                	ptr = save->next;
                	save = ptr->next;
            	} 
				else {
                	temp -> next = NULL;
                	ptr = NULL;
            	}
        	}
        	else{
                	temp -> next = save;
                	ptr = NULL;
                	temp = save;
                	ptr = save -> next;
                	save = ptr -> next;
            }
        }
    }
    void show()
    {
        cout << endl << endl;
        ptr = start;
        while(ptr!=NULL)
        {
            cout << ptr -> value << endl;
            ptr = ptr ->next;
        }
    }
};
int main(){
    ll obj1;
    int num;
    cin >> num;
    obj1.create_ll_back(num);
    obj1.show();
    obj1.delete1();
    obj1.show();
    return 0;
}
// pairwise swapping of elements.create ll 1,2,3,4,5
