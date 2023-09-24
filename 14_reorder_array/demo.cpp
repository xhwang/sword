
#include <iostream>


using namespace std;


void reorderArray(int* arr, int length) {

  if (arr == NULL || length == 0)
    return;

  int low = 0;
  int high = length - 1;

  while (low < high) {
  
    while (arr[low] % 2 == 1 && low < high)
      low++;

    while (arr[high] % 2 == 0 && low < high)
      high--;

    if (low < high) {
      int t = arr[low];
      arr[low] = arr[high];
      arr[high] = t;
    }

  }


}

void printArray(int* arr, int length) {
  for(int i=0; i < length; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}


int main() {

  int arr[5] = {1, 2, 3, 4, 5};
  printArray(arr, 5);
  reorderArray(arr, 5);
  printArray(arr, 5);

  return 0;
}
