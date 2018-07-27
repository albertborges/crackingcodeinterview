//
//  main.m
//  Executor
//
//  Created by Albert Borges on 7/19/18.
//  Copyright © 2018 Albert Borges. All rights reserved.
//

#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool oneAway( const char* str1, const char* str2 )
{
  // One away means the number of characters cannot differ by more than one
  unsigned int cch1 = strlen(str1);
  unsigned int cch2 = strlen(str2);
  unsigned int cchBigger = cch1 > cch2 ? cch1 : cch2;
  int difference =  cch1 - cch2;
  
  if(difference < 0)
    difference *= -1;
  
  // If the length of the strings differ by more than one, then it is not possible to be 'one away'
  if(difference > 1)
    return false;
  
  // Create iterators
  const char* iterBigger;
  const char* iterSmaller;
  if( cch1 >= cch2 )
  {
    iterBigger = str1;
    iterSmaller = str2;
  }
  else
  {
    iterBigger = str2;
    iterSmaller = str1;
  }
  
  // Find number of differences
  unsigned int numDifferences = 0;
  
  for(unsigned int i=0; i<cchBigger; i++)
  {
    if(*iterBigger != *iterSmaller)
    {
      numDifferences++;
      
      // If the strings are the same size, we don't need to offset iterBigger
      if(difference == 0)
        iterSmaller++;
    }
    else
    {
      iterSmaller++;
    }
    iterBigger++;
  }
  
  return numDifferences <= 1;
}

int main(int argc, const char * argv[]) {
  const char str1[] = "abc";
  const char str2[] = "abc";
  printf("%i", oneAway(str1, str2));
  return 0;
}

