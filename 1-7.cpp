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
#include <vector>
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

void Print(vector<vector<RGBA>> matrix, const int dimensions)
{
  for(int i=0;i<dimensions;i++)
  {
    for(int j=0;j<dimensions;j++)
    {
      std::cout << matrix[i][j].print();
    }
    std::cout << std::endl;
  }
}

void Initialize(vector<vector<RGBA>>& matrix, const int dimensions)
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

struct position
{
  position(int r, int c) :
  m_r(r),
  m_c(c)
  {}
  
  int m_r;
  int m_c;
};

void Rotate(vector<vector<RGBA>>& matrix, const int dimensions)
{
  int iters_max = dimensions-1;
  int iters_min = 0;
  int delta;
  
  while(iters_max-iters_min > 0)
  {
    delta = iters_max - iters_min;
    
    for(int c=0;c<delta;c++)
    {
      RGBA temp;
      
      // Upper left corner
      struct position pos1 = position(iters_min, iters_min+c);
      
      // Upper right corner
      struct position pos2 = position(iters_min+c, iters_max);
      
      // Lower right corner
      struct position pos3 = position(iters_max, iters_max-c);
      
      // Lower left corner
      struct position pos4 = position(iters_max-c,iters_min);
      
      RGBA& rpos1 = matrix[pos1.m_r][pos1.m_c];
      RGBA& rpos2 = matrix[pos2.m_r][pos2.m_c];
      RGBA& rpos3 = matrix[pos3.m_r][pos3.m_c];
      RGBA& rpos4 = matrix[pos4.m_r][pos4.m_c];
      
      // LTR
      temp = rpos2;
      rpos2 = rpos1;
      
      // RTB
      rpos1 = rpos3;
      rpos3 = temp;
      
      // BTL
      temp = rpos4;
      rpos4 = rpos1;
      
      // LTT
      rpos1 = temp;
    }
    
    iters_max--;
    iters_min++;
  }
}

int main(int argc, const char * argv[]) {
  const int dimensions = 4;
  vector<vector<RGBA>>matrix;
  matrix.resize(dimensions);
  
  for(int i=0;i<matrix.size();i++)
  {
    matrix[i].resize(dimensions);
  }
  
  Initialize(matrix, dimensions);
  
  Rotate(matrix, dimensions);
  
  Print(matrix, dimensions);
  
  return 0;
}


