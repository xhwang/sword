
#include <iostream>

using namespace std;


void helper(char* str, char* begin) {

  if (*begin == '\0') {
    cout<<str<<endl;
    return;
  }

  for(char* i = begin; *i != '\0'; i++) {
  
    char t = *begin;
    *begin = *i;
    *i = t;

    helper(str, begin + 1);

    t = *begin;
    *begin = *i;
    *i = t;
  }

}



void permutation(char* str) {

  if (not str)
    return;

  helper(str, str);
}

int main() {
  char str[] = "abc";
  permutation(str);
}
