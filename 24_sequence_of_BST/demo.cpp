
#include <iostream>
#include <vector>

using namespace std;

bool is_valid(vector<int> arr, int start, int end) {

  if (start >= end)
    return true;

  size_t len = arr.size();

  int root = arr[len-1];

  int i = start;
  while(i<end) {
    if (arr[i] > root)
      break;
    i++;
  }

  int mid = i;
  bool left = is_valid(arr, start, mid-1);

  while(i<end) {
    if (arr[i] < root) {
      return false;
    }
    i++;
  }

  bool right = is_valid(arr, mid, end-1);

  return left && right;
}


int main() {

  vector<int> arr;

  arr = {5, 7, 6, 9, 11, 10, 8};
  cout<<is_valid(arr, 0, arr.size()-1)<<endl;

  arr = {7, 4, 6, 5};
  cout<<is_valid(arr, 0, arr.size()-1)<<endl;

}
