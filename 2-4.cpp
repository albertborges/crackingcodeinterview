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
#include <list>
using namespace std;

void printlinkedlist(list<int>ll)
{
  list<int>::iterator iter;
  for(iter=ll.begin();iter!=ll.end();iter++)
  {
    cout << *iter;
    if((std::next(iter,1)!=ll.end()))
      cout << "->";
  }

  cout << endl;
}

void partition(list<int>& ll, int x)
{
  list<int> rightPartition;
  for(auto iter = ll.begin(); iter!=ll.end(); iter++)
  {
    // If less than partition, move to head
    if(*iter < x)
    {
      ll.push_front(*iter);
      ll.erase(iter);
    }
    // If greater than or equal to partition, move to temp list that will be appended after
    else
    {
      rightPartition.push_back(*iter);
      ll.erase(iter);
    }
  }

  // Append right partition
  ll.insert(ll.end(), rightPartition.begin(), rightPartition.end());
}

int main(int argc, const char * argv[]) {
  list<int> ll;
  ll.push_back(10);
  ll.push_back(7);
  ll.push_back(8);
  ll.push_back(4);
  ll.push_back(8);
  ll.push_back(4);

  printlinkedlist(ll);

  partition(ll, 8);

  printlinkedlist(ll);



  return 0;
}



