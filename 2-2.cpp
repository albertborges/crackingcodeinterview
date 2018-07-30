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

int target;

void kthtolast(list<int>::iterator ll, const list<int>::iterator llend, int& counter, int k)
{
  if(ll == llend)
  {
    counter++;
    return;
  }
  else
  {
    auto next = std::next(ll, 1);
    kthtolast(next, llend, counter, k);
  }
  
  if(counter == k)
    target = *ll;
  
  counter++;
  return;
}


int main(int argc, const char * argv[]) {
  list<int> ll;
  ll.push_back(5);
  ll.push_back(7);
  ll.push_back(8);
  ll.push_back(10);
  ll.push_back(8);
  ll.push_back(4);
  
  int counter = 0;
  kthtolast(ll.begin(), ll.end(), counter, 4);
  
  printlinkedlist(ll);
  cout << target << endl;
  
  return 0;
}



