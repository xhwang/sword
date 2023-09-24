// A Naive recursive program to find minimum 
// number insertions needed to make a string
// palindrome
#include <stdio.h>
#include <limits.h>
#include <string.h>
 
// A utility function to find minimum of two numbers
int min(int a, int b)
{  return a < b ? a : b; }
 
// Recursive function to find minimum number of 
// insertions
int findMinInsertions(char str[], int l, int h)
{
    // Base Cases
    if (l > h) {
      printf("Error\n");
      return INT_MAX;
    }
    if (l == h) return 0;
    if (l == h - 1) return (str[l] == str[h])? 0 : 1;
 
    // Check if the first and last characters are
    // same. On the basis of the comparison result, 
    // decide which subrpoblem(s) to call
    return (str[l] == str[h])? 
                     findMinInsertions(str, l + 1, h - 1):
                     (min(findMinInsertions(str, l, h - 1),
                     findMinInsertions(str, l + 1, h)) + 1);
}

int findMinInsertionsDP(char str[], int len) {

  int t[len][len];
  int l, h, gap;

  // necessary
  memset(t, 0, sizeof(t));

  // 按对角线的方式初始化
  for(gap = 1; gap < len; gap++) {
    for (l=0, h=gap; h < len; l++, h++) {
      t[l][h] = (str[l] == str[h]) ? t[l+1][h-1] : (min(t[l+1][h], t[l][h-1]) + 1);
    }
  }

  return t[0][len-1];
}

// Driver program to test above functions
int main()
{
    char str[] = "kgeeks";
    printf("%d\n", findMinInsertions(str, 0, strlen(str)-1));
    printf("%d\n", findMinInsertionsDP(str, strlen(str)));

    char str1[] = "kgaeks";
    printf("%d\n", findMinInsertions(str1, 0, strlen(str1)-1));
    printf("%d\n", findMinInsertionsDP(str1, strlen(str1)));

    char str2[] = "skseesks";
    printf("%d\n", findMinInsertions(str2, 0, strlen(str2)-1));
    printf("%d\n", findMinInsertionsDP(str2, strlen(str2)));

    return 0;
}

