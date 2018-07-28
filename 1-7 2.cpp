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
#include <iostream>
using namespace std;

struct RGBA
{
  unsigned char red;
  unsigned char green;
  unsigned char blue;
  unsigned char alpha;
  
  char print()
  {
    if(red==0xff&&green==0x0&&blue==0x0&&alpha==0xff)
    {
      return 'R';
    }
    if(red==0x0&&green==0xff&&blue==0x0&&alpha==0xff)
    {
      return 'G';
    }
    if(red==0x0&&green==0x0&&blue==0xff&&alpha==0xff)
    {
      return 'B';
    }
    if(red==0xff&&green==0xff&&blue==0xff&&alpha==0xff)
    {
      return 'W';
    }
    return 'N';
  }
};

void Initialize(RGBA** matrix, const int dimensions)
{
  std::cout << "Initializing..." << std::endl;
  
  for(int i=0;i<dimensions;i++)
  {
    for(int j=0;j<dimensions;j++)
    {
      struct RGBA rgba;
      
      if(i==0)
      {
        rgba.red=(char)255;
        rgba.green=0;
        rgba.blue=0;
        rgba.alpha=(char)255;
      }
      if(i==1)
      {
        rgba.red=0;
        rgba.green=(char)255;
        rgba.blue=0;
        rgba.alpha=(char)255;
      }
      if(i==2)
      {
        rgba.red=0;
        rgba.green=0;
        rgba.blue=(char)255;
        rgba.alpha=(char)255;
      }
      if(i==3)
      {
        rgba.red=(char)255;
        rgba.green=(char)255;
        rgba.blue=(char)255;
        rgba.alpha=0xff;
      }
      matrix[i][j] = rgba;
      std::cout << rgba.print();
    }
    std::cout << std::endl;
  }
}

int main(int argc, const char * argv[]) {
  const int dimensions = 4;
  RGBA matrix[dimensions][dimensions];
  Initialize(matrix, dimensions);
  
  return 0;
}


