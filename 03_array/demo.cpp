#include <iostream>

#include <vector>
using namespace std;


int getSize(int data[]) {
  return sizeof(data);
}

void testArray() {

  // TODO: x64 pointer 8 byte, int 4 byte
  int arr[] = {1, 2, 3};
  cout<<sizeof(arr)<<endl;

  int* p = arr;
  cout<<sizeof(p)<<endl;

  int sz = getSize(arr);
  cout<<sz<<endl;
}


bool findElement(vector<vector<int>> m, int num) {

  bool rel = false;

  int row = m.size();
  if (row == 0)
    return rel;

  int col = m[0].size();
  if (col == 0)
    return rel;

  int colBegin = col-1;
  int rowBegin = 0;

  while (rowBegin < row && colBegin >= 0) {
  
    int t = m[rowBegin][colBegin];

    if (t == num) {
      rel = true;
      break;
    }
    else if (t < num) {
      rowBegin++;
    }
    else {
      colBegin--;
    }
  }

  return rel;
}


int main() {

  testArray();

  vector<vector<int>> m = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};

  int num;

  num = 7;
  cout<<num<<": "<<findElement(m, num)<<endl;
  num = 1;
  cout<<num<<": "<<findElement(m, num)<<endl;
  num = 15;
  cout<<num<<": "<<findElement(m, num)<<endl;

  num = 5;
  cout<<num<<": "<<findElement(m, num)<<endl;
  num = -1;
  cout<<num<<": "<<findElement(m, num)<<endl;
  num = 17;
  cout<<num<<": "<<findElement(m, num)<<endl;

  return 0;
}
