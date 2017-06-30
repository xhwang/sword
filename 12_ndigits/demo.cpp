
#include <cstring>
#include <iostream>


using namespace std;


void printOwn(char* s) {

  int len = strlen(s);

  int i = 0;
  for (; i<len; i++) {
    if (s[i] != '0')
      break;
  }

  if (i == len)
    return;

  char* buff  = new char[len-i];
  memcpy(buff, &s[i], len-i);

  cout<<buff<<endl;

  delete []buff;
}


void help(char* s, int len, int n) {

  if (n == len) {
    printOwn(s);
    return;
  }

  for (int i=0;i<=9;i++) {
    s[n] = '0' + i;
    help(s, len, n+1);
  }

}


void printNDigits(int n) {
  char* s = new char[n+1];
  for (int i = 0; i<n; i++)
    s[i] = '0';

  help(s, n, 0);

  delete []s;
}


int main() {
  printNDigits(2);
}
