
#include "assign.h"
#include <cstring>
#include <iostream>
using namespace std;


class Empty {
public:
  Empty(){}

  // TODO: virtual function table pointer
  // http://www.learncpp.com/cpp-tutorial/125-the-virtual-table/
  virtual void getData() {};
  virtual void getNum() {};
};


int main() {

  Empty e = Empty();
  cout<<sizeof(e)<<endl;

  // TODO: delete NULL is OK
  char* temp = NULL;
  delete []temp;

  char* t = new char[5];
  strcpy(t, "ABCD");
  // TODO: after delete t is ""
  delete []t;

  char* pData = new char[5];
  strcpy(pData, "ABCD");
  CMyString str(pData);
  cout<<str.getData()<<endl;

  strcpy(pData, "DCBA");
  CMyString str1(pData);

  // TODO: copy constructor
  // 1. CMyString str2(str1);
  // 2. CMyString str2 = str1;
  CMyString str2 = str1;
  cout<<str1.getData()<<endl;
  cout<<str2.getData()<<endl;

  // TODO: default assign is shallow
  str = str;
  cout<<str.getData()<<endl;

  str1 = str;
  cout<<str.getData()<<endl;
  cout<<str1.getData()<<endl;

  str2 = str1 = str;
  cout<<str.getData()<<endl;
  cout<<str2.getData()<<endl;

  return 0;
}
