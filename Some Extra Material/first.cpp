#include <iostream>
using namespace std;

class array
{
    int * arr;
    int size;
public:
    void create()
    {
        cin >> size;
        arr= new int[size];
    }
    void resize()
    {

    }
    void deletion()
    {

    }
    void output()
    {

    }
    void binary_search(int key)
    {
        int beg,end,mid;
        beg=0;
        end=size-1;
        while(beg<=end)
        {
            mid=(beg+end)/2;
            if(a[mid]==key)
            {
                cout << "Element found at position: " << mid;
                break;
            }
            else if(a[mid]<key)
            {
                end = mid - 1;
            }
            else
            {
                beg = mid + 1;
            }
        }
        if (end<beg)
            cout << "Element not found" ;
    }
};
int main()
{
    array a1;
    int flag=0,sw;
    while(flag==0)
    {
        cout << "Welcome to this program" << endl;
        cout << "Please enter the serial number of the option you want to try " << endl;
        cout << "1. Create an Array" << endl;
        cout << "2. Output the Array " << endl;
        cout << "3. Resize the Array" << endl;
        cout << "4. Delete an element of the Array" << endl;
        cout << "5. Searching for an element in the array" << endl;
        cout << ""
        switch (sw)
        {
            case 1:

        }
    }
}