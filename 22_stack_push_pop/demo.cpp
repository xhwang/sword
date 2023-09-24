
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


bool isCorrectOrder(vector<int> nums, vector<int> order) {

  bool rel = true;
  stack<int> s;

  if (not nums.size() or nums.size() != order.size())
    return false;

  size_t i = 0;

  for (size_t j=0; j<order.size(); j++) {

    if (s.empty() || s.top() != order[j]) {

      while (true) {
        s.push(nums[i]);

        if (nums[i] == order[j]) {
          i++;
          break;
        }

        i++;
        if (i >= nums.size())
          return false;

      }
    }

    s.pop();

  }

  return rel;
}



int main() {

  vector<int> nums = {1, 2, 3, 4, 5};

  vector<int> order;

  order = {4, 5, 3, 2, 1};
  cout<<isCorrectOrder(nums, order)<<endl;

  order = {4, 3, 5, 1, 2};
  cout<<isCorrectOrder(nums, order)<<endl;

}
