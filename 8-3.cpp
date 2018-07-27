#include <iostream>
using namespace std;

struct range
{
  int startindex;
  int endindex;
};

// O(log(n))
bool binarysearch(int* arr, int size, int& magicindex)
{
  struct range currange;
  currange.startindex = 0;
  currange.endindex = size - 1;
  while( currange.endindex >= currange.startindex )
  {
    int curnext = (currange.endindex + currange.startindex) / 2;
    if(arr[curnext] == curnext)
    {
      magicindex = curnext;
      return true;
    }
    else if(arr[curnext] > curnext)
    {
      // we need to look beforehand
      currange.endindex = curnext - 1;
    }
    else
    {
      // we need to look forward
      currange.startindex = curnext + 1;
    }
  }
  
  return false;
}

int main () {
  int test1[8] = {-20,-10,-5,-2,4,8,9,0};
  int test2[7] = {-20,-10,-2,3,8,9,0};
  int test3[3] = {1,2,0};
  int test4[4] = {0,1,2,0};
  int test5[8] = {-20,-10,-5,-2,5,8,9,0};
  int test6[7] = {-20,-10,-2,6,8,9,0};
  int magicindex = -1;
  
  cout << binarysearch(test6, 6, magicindex ) << endl;
  cout << magicindex << endl;
  return 0;
}
