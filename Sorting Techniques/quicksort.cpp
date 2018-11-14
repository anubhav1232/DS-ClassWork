#include <iostream>
using namespace std;

class QSort{
    int * arr;
    int size;
    int p, q, r, pivot, temp;
public:
    void c_arr(int &a, int &b){
    	cout << "enter the size of the array" << endl;
    	cin >> size;
        arr = new int(size);
        cout << "enter the array elements" << endl;
        for(int i = 0; i < size; i++){
            cin >> arr[i];
        }
        p = 0;
        r = size - 1;
        a = p;
        b = r;
    }
    int part_algo(int p, int r){
        pivot = arr[r];
        int j = p - 1;
        for(int i = p; i < r; i++){
            if(arr[i] <= pivot){
                j = j + 1;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[j + 1];
        arr[j + 1] = arr[r];
        arr[r] = temp;
        return(j + 1);
    }
    void QS(int p, int r){
        if(p < r){
            q = part_algo(p, r);
            QS(p, q - 1);
            QS(q + 1, r);
        }
    }
    void display(){
        cout << endl;
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    QSort a1;
    int n;
    int p = 0, r = 0;
    cout << "this program is for quick sort" << endl;
    cout << "1. creating array" << endl << "2. quick sort operation" << endl;
    cout << "3. displaying the array" << endl;
    cout << "enter -1 to exit program" << endl;
    cin >> n;
    while(n!=-1) {
        switch (n) {
            case 1: {
                a1.c_arr(p,r);
                break;
            }
            case 2: {
                a1.QS(p,r);
                break;
            }
            case 3: {
                a1.display();
                break;
            }
            default: {
                cout << "invalid input" << endl;
            }
        }
        cout << "1. creating array" << endl << "2. quick sort operation" << endl;
        cout << "3. displaying the array" << endl;
        cout << "enter -1 to exit program" << endl;
        cin >> n;
    }
}
