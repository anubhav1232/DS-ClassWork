#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct B_T{
    int num;
    struct B_T *left;
    struct B_T *right;
} *new_B_T_N, *ptr, *root, *parent_, *parent[20];
int flag = 0;
int count = 0;
int flag1 = 1;
queue<struct B_T*> myqueue;
stack<struct B_T*> stk;

void create_tree(int n1){
    while(n1 >= 0) {
        if(count == 0) {
            new_B_T_N = new B_T;
            new_B_T_N -> num = n1;
            new_B_T_N -> right = NULL;
            new_B_T_N -> left = NULL;
            ptr = new_B_T_N;
            root = new_B_T_N;
            parent[count] = new_B_T_N;
            count = 1;
            cout << "enter the next number" << endl;
            cin >> n1;
        }
        else {
            if(n1 <= ptr ->num){
                if(ptr -> left == NULL) {
                    new_B_T_N = new B_T;
                    new_B_T_N ->num = n1;
                    ptr -> left = new_B_T_N;
                    new_B_T_N -> left = NULL;
                    new_B_T_N -> right = NULL;
                    cout << "parent B_T_N is: " << ptr -> num << endl;
                    ptr = root;
                    cout << "enter the next number" << endl;
                    cin >> n1;
                    continue;
                }
                else {
                    ptr = ptr -> left;
                    continue;
                }
            }
            else {
                if(ptr -> right == NULL) {
                    new_B_T_N = new B_T;
                    new_B_T_N ->num = n1;
                    ptr -> right = new_B_T_N;
                    new_B_T_N -> left = NULL;
                    new_B_T_N -> right = NULL;
                    cout << "parent B_T_N is: " << ptr -> num << endl;
                    ptr = root;
                    cout << "enter the next number" << endl;
                    cin >> n1;
                    continue;
                }
                else{
                    ptr = ptr -> right;
                    continue;
                }
            }
        }
    }
}
void inorder(struct B_T *copy){
	if (copy == NULL){
		//cout << "in if" << endl;
        return;
		}
    //cout << "call of " << copy -> num << " left " << endl;
    inorder(copy -> left);
    //cout << "print of " << copy -> num << endl;
    cout << copy -> num << " ";
    //cout << "call of " << copy -> num << " right" << endl;
    inorder(copy ->right);
}
void preorder(struct B_T *copy){
	if (copy == NULL){
		//cout << "in if" << endl;
        return;
		}
    //cout << "print of " << copy -> num << endl;
    cout << copy -> num << " ";
    //cout << "call of " << copy -> num << " left " << endl;
    preorder(copy -> left);
    //cout << "call of " << copy -> num << " right" << endl;
    preorder(copy ->right);
}
void postorder(struct B_T *copy){
	if (copy == NULL){
		//cout << "in if" << endl;
        return;
		}
    //cout << "call of " << copy -> num << " left " << endl;
    postorder(copy -> left);
    //cout << "call of " << copy -> num << " right" << endl;
    postorder(copy ->right);
    //cout << "print of " << copy -> num << endl;
    cout << copy -> num << " ";
}
void searching(int n1) {
    ptr = root;
    parent_ = NULL;
    while(true) {
    	if(ptr -> num == n1 && ptr == root) {
    		cout << "number present" << endl;
    		break;
    	}
        else if(ptr -> num == n1) {
            cout << "number found" << endl;
            cout << "parent is: " << parent_ -> num << endl;
            break;
        }
        else if(ptr -> num > n1 && ptr -> left != NULL) {
            parent_ = ptr;
            ptr = ptr -> left;
            continue;
        }
        else if(ptr -> num < n1 && ptr -> right != NULL) {
            parent_ = ptr;
            ptr = ptr -> right;
            continue;
        }
        else {
            cout << "number not present" << endl;
            break;
        }
    }
}

int minimum(B_T *copy) {
    ptr = copy;
    while(ptr -> left != NULL) {
        ptr = ptr -> left;
    }
    cout << "minimum value is: " << ptr -> num << endl;
    return ptr -> num;
}

int maximum(B_T *copy) {
    ptr = copy;
    while(ptr -> right != NULL) {
        ptr = ptr -> right;
    }
    cout << "maximum value is: " << ptr -> num << endl;
    return ptr -> num;
}

void level_display(int option){
    ptr = root;
    myqueue.push(ptr);
    while(!myqueue.empty()){
        myqueue.pop();
        cout << "level value: " << ptr -> num << endl;
        if (option == 1) {
            if (ptr->left != NULL)
                myqueue.push(ptr->left);
            if (ptr->right != NULL)
                myqueue.push(ptr->right);
        }
        else if(option == 2) {
            if (ptr->right != NULL)
                myqueue.push(ptr->right);
            if (ptr->left != NULL)
                myqueue.push(ptr->left);
        }
        ptr = myqueue.front();
    }
}

void pre_no_recursion() {
    stk.push(root);
    while(!stk.empty()) {
        ptr = stk.top();
        stk.pop();
        cout << "Value: " << ptr -> num << endl;
        if(ptr -> right != NULL)
            stk.push(ptr -> right);
        if(ptr -> left != NULL)
            stk.push(ptr -> left);
    }
    cout << "tree displayed" << endl;
}

void in_no_recursion() {
	stk.push(root);
	flag = 0;
	while(!stk.empty()) {
		ptr = stk.top();
		if (flag == 0) {
			if(ptr -> left == NULL) {
				flag = 1;
				continue;
			}
			stk.push(ptr -> left);
		}
		if (flag == 1) {
			stk.pop();
			cout << ptr -> num << " ";
			if (ptr -> right != NULL) {
				flag = 0;
				stk.push(ptr -> right);
			}
		}
	}
}

void del_leafnode(B_T* save, B_T* copy) {
	if(copy -> num <= save -> num) {
		save -> left = NULL;
	}
	else if(copy -> num > save -> num) {
		save -> right = NULL;
	}
}

void search_del(int num) {
	ptr = root;
	B_T *save = ptr;
	int min = (minimum(root));
	int max = (maximum(root));
	int flag_ = 0;
	while(num <= max) {
		if(ptr -> num == num) {
			if(ptr -> left == NULL && ptr ->right == NULL) {
				del_leafnode(save,ptr);
				flag_ = 1;
				break;
			}
			else if(ptr -> left != NULL && ptr -> right == NULL) {
				del_2child(ptr);
				flag_ = 1;
				break;
			}
			else if(ptr -> left != NULL || ptr -> right != NULL) {
				
				flag_ = 1;
				break;
			}
		}
		else {
			if(ptr -> left -> num <= num && ptr -> left != NULL) {
				save = ptr;
				ptr = ptr -> left;
			}
			else if(ptr -> right -> num > num && ptr -> right != NULL){
				save = ptr;
				ptr = ptr -> right;
			}
			else {
				break;	
			}
		}
	}
	if(flag_ == 1) {
		cout << "The element has been deleted" << endl;
	}
}


void display_tree() {
    ptr = root;
    flag = 0;
    parent_ = NULL;
    while (true) {
        if(ptr -> left != NULL && ptr -> right != NULL){
            cout << ptr -> num << " ";
            parent_ = ptr;
            ptr = ptr -> left;
            flag = 1;
            continue;
        }
        else if(ptr -> left != NULL && ptr -> right == NULL && flag == 1) {
				
        }
    }
}
int main() {
	int n1, n, extra;
	B_T *extra1;
	cout << "This is a program for operations with binary tree" << endl;
	cout << "Enter one of the options for it's respective operation " << endl;
	cout << "1. Creating Binary Tree" << endl << "2. Searching for some element" << endl << "3. Finding maximum Element" << endl << "4. Finding minimum element" << endl;
	cout << "5. Preorder Display" << endl << "6. Inorder display" << endl << "7. Postorder Display" << endl << "8. level order display" << endl << "9.deleting a specific number(node) from tree" << endl;
	cout << "Also note that to exit/end any execution phase, please enter -1" << endl;
	cin >> n;
	while(n > 0){
		switch (n){
			case 1:{
				cout << "enter the numbers to be added into the binary tree , entering negative number will terminate the program" << endl;
    			cin >> n1;
    			create_tree(n1);
				break;
			}
			case 2: {
				cout << "enter the number you want to find in the tree" << endl;
    			cin >> n1;
    			searching(n1);
				break;
			}
			case 3: {
				cout << "finding the maximum element of the tree" << endl;
				extra1->num = maximum(root);
				break;
			}
			case 4: {
				cout << "finding the maximum element of the tree" << endl;
				extra1->num = minimum(root);
				break;
			}
			case 5: {
                cout << "please enter the following option for resultant display" << endl;
                cout << "1. preorder display with recursion" << endl << "2. preorder display without recursion" << endl;
                cin >> n1;
                if(n1 == 1) {
                    preorder(root);
                    break;
                }
                if(n1 == 2) {
                    pre_no_recursion();
                    break;
                }
                cout << "wrong input, please try again" << endl;
			}
			case 6: {
				cout << "please enter the following option for resultant display" << endl;
                cout << "1. inorder display with recursion" << endl << "2. inorder display without recursion" << endl;
                cin >> n1;
                if (n1 == 1) {
					inorder(root);
					break;
				}
				if (n1 == 2) {
					in_no_recursion();
					break;
				}
				cout << "wrong input, please try again" << endl;
			}
			case 7: {
				postorder(root);
				break;
			}
            case 8: {
                cout << "please enter the following option for resultant display" << endl;
                cout << "1. left to right display" << endl << "2. right to left display" << endl;
                cin >> n1;
                if (n1 == 1 || n1 == 2)
				    level_display(n1);
                else
                    cout << "wrong option, please try again" << endl;
                break;
            }
            case 9: {
            	cout << "please enter the number you want to delete" << endl;
            	cin >> n1;
            	search_del(n1);
            	break;
            }
            default: {
                cout << "Wrong option, please try again" << endl;
                break;
            }
		}
		cout << endl;
        cout << "1. Creating Binary Tree" << endl << "2. Searching for some element" << endl << "3. Finding maximum Element" << endl << "4. Finding minimum element" << endl;
		cout << "5. Preorder Display" << endl << "6. Inorder display" << endl << "7. Postorder Display" << endl << "8. level order display" << endl << "9.deleting a specific number(node) from tree" << endl;
        cout << "Also note that to exit/end any execution phase, please enter -1" << endl;
		cin >> n;
	}
    return 0;
}
