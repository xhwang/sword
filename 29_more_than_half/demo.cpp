
#include <iostream>
#include <vector>

using namespace std;


int findMoreThanHalf(const vector<int>& array) {

  int rel = array[0];
  int time = 1;

  for (size_t i = 1; i<array.size(); i++) {

    if (rel == array[i]) {
      time++;
    }
    else {
      time--;
      if (time == 0) {
        rel = array[i];
        time = 1;
      }
    }

  }

  return rel;
}

int main() {
  vector<int> array = {1, 2, 2, 5, 2};
  int rel = findMoreThanHalf(array);
  cout<<rel<<endl;
}
