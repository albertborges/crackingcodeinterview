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

struct Node
{
  int x;
  Node* next;
};

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


int main(int argc, const char * argv[]) {
  list<int> ll;
  ll.push_back(5);
  ll.push_back(7);
  ll.push_back(8);
  ll.push_back(10);
  ll.push_back(8);
  ll.push_back(4);
  
  printlinkedlist(ll);
  
  unordered_set<int> vars_seen;
  for(auto iter=ll.begin();iter!=ll.end();iter++)
  {
    if(vars_seen.find(*iter) != vars_seen.end())
    {
      ll.erase(iter);
    }
    else
    {
      vars_seen.insert(*iter);
    }
  }
  
  printlinkedlist(ll);
  
  return 0;
}



