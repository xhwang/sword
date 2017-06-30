
#include <iostream>

using namespace std;


void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}


int partition(int data[], int start, int end) {

  int count = 0;
  int index = 3;
  swap(data[index], data[end]);
  count += 3;

  int small = start-1;
  for(index=start; index<end; index++) {
    if(data[index] < data[end]){
      ++small;
      if(small != index) {
          swap(data[small], data[index]);
          count += 3;
      }
    }
  }

  ++small;
  swap(data[small], data[end]);
  count += 3;
  cout<<count<<endl;

  return small;

}

int partition_eff(int data[], int start, int end) {

  int count = 0;

  int index = 3;

  int temp = data[index];
  swap(data[index], data[end]);
  count += 3;

  int i = start;
  int j = end;

  while(i<j) {

    while(data[i]<temp && i<j)
      i++;
    if(i<j) {
      count++;
      data[j] = data[i];
      j--;
    }

    while(data[j]>temp && i<j)
      j--;
    if(i<j) {
      count++;
      data[i] = data[j];
      i++;
    }
  }

  count++;
  data[i] = temp;

  cout<<count<<endl;

  return i;
}

int main() {

  int v[] = {32, 25, 45, 32, 78, 12, 29, 64};

  cout<<partition_eff(v, 0, 7)<<endl;

  for(int i = 0; i<8; i++) {
    cout<<v[i]<<" ";
  }
  cout<<endl;

}
