#include <iostream>
#include <cstring>
using namespace std;

char* replaceSpace(char* str) {

  if (str == nullptr)
    return nullptr;

  int len = strlen(str);
  cout<<len<<endl;

  int numSpace = 0;
  for(int i=0; i<len; i++) {
    if(str[i] == ' ')
      numSpace++;
  }

  int newLen = len + 2*numSpace;

  while (newLen != len) {
    if(str[len] != ' ') {
      str[newLen] = str[len];
      newLen--;
    }
    else {
      str[newLen--] = '0';
      str[newLen--] = '2';
      str[newLen--] = '%';
    }
    len--;
  }

  return str;
}

int main() {
  char str[] = "Hello World";
  cout<<replaceSpace(str)<<endl;

  char str1[] = " World";
  cout<<replaceSpace(str1)<<endl;

  char str2[] = "  ";
  cout<<replaceSpace(str2)<<endl;

  char str3[] = "a  ";
  cout<<replaceSpace(str3)<<endl;

  char str4[] = "abc";
  cout<<replaceSpace(str4)<<endl;

  char str5[] = "";
  cout<<replaceSpace(str5)<<endl;

  char* str6 = nullptr;
  cout<<replaceSpace(str6)<<endl;
}
