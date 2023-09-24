
#include "../utils/tree.h"
#include <iostream>
#include <queue>

using namespace std;


void foo1(int *arr) { cout << sizeof(arr) << '\n'; }
void foo2(int arr[]) { cout << sizeof(arr) << '\n'; }
void foo3(int arr[10]) { cout << sizeof(arr) << '\n'; }

// Note: not recommmanded, use vector instead
// Reference to an array
void foo4(int (&arr)[10]) { 
  cout << sizeof(arr) << '\n'; 
  arr[0] = 0;
}

// Pointer to an array
void foo5(int (*arr)[10]) { 
  cout << sizeof(*arr) << '\n'; 
}

void foo6(vector<int> v) { 
  v[0] = 0;
}

void foo7(vector<int>& v) { 
  v[0] = 0;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    foo1(arr);
    foo2(arr);
    foo3(arr);

    cout<<arr[0]<<endl;
    foo4(arr);
    cout<<arr[0]<<endl;

    foo5(&arr);

    cout<<"vecotr"<<endl;

    vector<int> v = {1, 2, 3};

    cout<<v[0]<<endl;
    foo6(v);
    cout<<v[0]<<endl;

    cout<<v[0]<<endl;
    foo7(v);
    cout<<v[0]<<endl;
}
