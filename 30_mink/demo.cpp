
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<int> findMinK(vector<int>& array, int k) {

  vector<int> rel;

  // TODO: less greater
  priority_queue<int, vector<int>, greater<int>> q(array.begin(), array.end());

  for (int i = 0; i<k; i++) {
    rel.push_back(q.top());
    q.pop();
  }

  return rel;
}


int main() {

  vector<int> array = {1, 2, 3, 4, 5};

  vector<int> rel = findMinK(array, 3);

  for (auto i: rel)
    cout<<i<<" ";
  cout<<endl;

  return 0;
}
