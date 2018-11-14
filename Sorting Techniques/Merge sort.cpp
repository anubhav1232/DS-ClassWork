#include <iostream>
using namespace std;

class array {
    int *arr;
    int *arr2;
    int *arr3;
    int num;
    int ele;
public:
    void ary2(int p){
        arr2 = new int(p);
    }
    void ary3(int q){
        arr3 = new int(q);
    }
    void ary(int size){
        arr = new int(size);
    }
    void CA(int &p, int &r){
        cout << "Enter array size" << endl;
        cin >> ele;
        ary(ele);
        cout << "enter array elements" << endl;
        for(int i= 0; i < ele; i++){
            cin >> arr[i];
        }
        p = 0;
        r = ele;
    }
    void MS(int p, int r){
    	//cout << "i'm in merge sort";
        if(p < r){
            int q = (p+r)/2;
            MS(p, q);
            MS((q+1), r);
            Merging(p, q, r);
        }
    }
    void Merging(int p, int q, int r){
        int n1 = q - p + 1;
        int n2 = r - q;
        cout << p << " " << q << " " << r << " " << n1 << " " << n2 << endl;
        int x = p;
        ary2(n1);
        ary3(n2);
        int j = 0;
        for(int i = 0; i < n1; i++) {
            arr2[i] = arr[p+i];
            p++;
        }
        for(int i = 0; i < n2; i++){
            arr3[i] = arr[q+1+i];
            q++;
        }
        int c1 = 0;
        int c2 = 0;
        int c3 = x;
        while(c1 < n1-1 && c2 < n2-1){
            if(arr2[c1] < arr3[c2]){
                arr[c3] = arr2[c1];
                c1++;
                c3++;
            }
            else{
                arr[c3] = arr3[c2];
                c2++;
                c3++;
            }
        }
        while(c1 < n1){
        	arr[c3] = arr2[c1];
        	c1++;
        	c3++;
        }
        while(c2 < n2){
        	arr[c3] = arr3[c2];
            c2++;
            c3++;
        }
        delete arr2;
        delete arr3;
    }
    void Display(){
        for(int i = 0; i < ele; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    array a1;
    int n;
    int p = 0, r = 0;
    cout << "this program is for merge sort" << endl;
    cout << "1. creating array" << endl << "2. merge sort operation" << endl;
    cout << "3. displaying the array" << endl;
    cout << "enter -1 to exit program" << endl;
    cin >> n;
    while(n!=-1) {
        switch (n) {
            case 1: {
                a1.CA(p,r);
                //cout << p << " " << r;
                break;
            }
            case 2: {
                a1.MS(p,r);
                break;
            }
            case 3: {
                a1.Display();
                break;
            }
            default: {
                cout << "invalid input" << endl;
            }
        }
        cout << "1. creating array" << endl << "2. merge sort operation" << endl;
        cout << "3. displaying the array" << endl;
        cout << "enter -1 to exit program" << endl;
        cin >> n;
    }
}
