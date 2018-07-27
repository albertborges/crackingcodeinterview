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

std::string compressString(const char* str)
{
  // The maximum length of the string returned is the length of the original string
  unsigned int length = strlen(str);
  const unsigned int lengthCompStr = length + 1;
  char compstr[lengthCompStr];
  
  for(unsigned int i=0;i<lengthCompStr;i++)
  {
    compstr[i]=0;
  }
  
  // Number of characters written
  int cch = 0;
  
  // Current character iterating
  char curr = 0;
  
  // Counter for number of instances found
  int found = 0;
  for(int i=0; i<length; i++)
  {
    // New character found
    if(str[i] != curr)
    {
      if(curr != 0)
      {
        if(cch+2>length)
        {
          std::string ret(str);
          return ret;
        }
        
        // Write to compressed string
        compstr[cch] = curr;
        compstr[cch+1] = '0' + found;
        cch+=2;
      }
      
      curr = str[i];
      found=1;
    }
    else
    {
      found++;
    }
    
    if(i == length-1)
    {
      if(cch+2>length)
      {
        std::string ret(str);
        return ret;
      }
      
      // Write to compressed string
      compstr[cch] = curr;
      compstr[cch+1] = '0' + found;
      cch+=2;
    }
  }
  
  std::string ret(compstr);
  return ret;
}

int main(int argc, const char * argv[]) {
  const char str1[] = "aabcccccaaa";
  
  printf("%s", compressString(str1).c_str());
  return 0;
}

