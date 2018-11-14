#include <iostream>
using namespace std;

/*struct B_T{
    int num;
    struct B_T *left;
    struct B_T *right;
} *new_B_T_N, *ptr, *root, *parent_, *parent[20];*/

class Heaps
{
	int m_size, *arr, largest , smallest, heapstyle;
public:
	void Heaps1(int size){
		m_size = size;
		arr = new int(size);
	}
	void enterarrvalues(){
		for(int i = 0; i < m_size ; i++){
			cin >> arr[i];
		}
	}
	void maxheap(int a){
		a = a - 1;
		//cout << "value of a is: " << a << endl;
		int flag = 0;
		largest = a;
		int l = (a * 2) + 1;
		int r = (a * 2) + 2;
		//cout << "amx";
		if(l < m_size && arr[l] > arr[largest]) {
			flag = 1;
			largest = l;
		}
		else if(l <= m_size && arr[l] < arr[a]) {
			largest = a;
		}
		if(r < m_size && arr[r] > arr[largest]) {
			flag = 1;
			largest = r;
		}
		if(flag == 1) {
			int temp = arr[a];
			arr[a] = arr[largest];
			arr[largest] = temp;
			//cout << arr[largest] << " " << largest << endl << "maxheap called" << endl;
			maxheap(largest);
		}
	}
	void maxheap1(){
		for(int i = m_size/2; i >= 1;i--) {
			maxheap(i);
			heapstyle = 0;
		}
	}
	void minheap(int a) {
		a = a - 1;
		//cout << "value of a is: " << a << endl;
		int flag = 0;
		smallest = a;
		int l = (a * 2) + 1;
		int r = (a * 2) + 2;
		//cout << "amx";
		if(l < m_size && arr[l] < arr[smallest]) {
			flag = 1;
			smallest = l;
		}
		else if(l <= m_size && arr[l] > arr[a]) {
			smallest = a;
		}
		if(r < m_size && arr[r] < arr[smallest]) {
			flag = 1;
			smallest = r;
		}
		if(flag == 1) {
			int temp = arr[a];
			arr[a] = arr[smallest];
			arr[smallest] = temp;
			//cout << arr[largest] << " " << largest << endl << "maxheap called" << endl;
			minheap(smallest);
		}
	}
	void minheap1(){
		for(int i = m_size/2; i >= 1;i--) {
			minheap(i);
			heapstyle = 1;
		}
	}
	void deletenode() {
		int temp = arr[0];
		arr[0] = arr[m_size-1];
		arr[m_size-1] = temp;
		arr = new int(m_size-1)
		//cout << "please select the configuration of tree: " << endl;
		if(heapstyle == 0) {
			maxheap1();
		}
		else if(heapstyle == 1) {
			minheap1();
		}
	}
	void displayarr() {
		for(int i = 0; i < m_size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main(){
	int count = 0, n, size, extra = 0, choise;
	char a;
	Heaps obj[5];
	cout << "This is a program for operations with Heaps" << endl;
	cout << "Enter one of the options for it's respective operation " << endl;
	cout << "1. Create Array" << endl << "2. Heapify the chosen Array" << endl << "3. Display the input array" << endl;
	cout << "Also note that to exit/end any execution phase, please enter -1" << endl;
	cin >> n;
	while(n != -1) {
		switch (n) {
			case 1: {
				if(extra == 0) {
					cout << "Enter the array size" << endl;
					cin >> size;
					obj[count].Heaps1(size);
					obj[count].enterarrvalues();
					extra = 1;
				}
				else if(count < 5){
					cout << "Do you really wish to create another instance of Heap" << endl;
					cout << "Note that " << (5-count) << " instances can be created" << endl;
					cout << "enter 'Y' if yes else enter any other character for no" << endl;
					cin >> a;
					if(a == 'Y' || a == 'y') {
						count ++;
						cout << "Enter the new array size" << endl;
						cin >> size;
						obj[count].Heaps1(size);
						obj[count].enterarrvalues();
					}
				}
				else {
					cout << "No more Availiable Space for new instances" << endl;
				}
				break;
			}
			case 2: {
				if(count == 0) {
					cout << "Please Enter a given option for Heapification" << endl;
					cout << "A. Max Heap" << endl << "B. Min Heap" << endl;
					cin >> a;
					if(a == 'a' || a == 'A') {
						obj[count].maxheap1();
					}
					else if(a == 'b' || a == 'B') {
						obj[count].minheap1();
					}
				}
				/*else if(count > 0 && count < 5) {
					cout << "please mention which heap you wish to apply the operations to : example '1' for first heap and so on " << endl;
					cin >> choise;
					choise -= 1;
					if (choise <= count) {
						cout << "Please Enter a given option for Heapification" << endl;
						cout << "A. Max Heap" << endl << "B. Min Heap" << endl;
						cin >> a;
						if(a == 'a' || a == 'A') {
							obj[choise].maxheap1();
						}
						else if(a == 'b' || a == 'B') {
							obj[choise].minheap1();
						}
					}
					else {
						cout << "no heap for the choise, please retry " << endl;
					}
				}
				else {
					cout << "program out of bounds" << endl;
				}*/
				break;
			}
			case 3: {
				cout << "array's current position: ";
				obj[count].displayarr();
				cout << endl;
				break;
			}
			default: {
				cout << "enter a valid input" << endl;
			}
		}
	cout << "1. Create Array" << endl << "2. Heapify the chosen Array" << endl << "3. Display the input array" << endl;
	cout << "Also note that to exit/end any execution phase, please enter -1" << endl;
	cin >> n;
	}
	return 0;
}

//add the element at the end of the heap, compare the inserted element with it's parents, if > than parent then swap the values, reeat this step again and again
//till the time element find's it's correct position
//
