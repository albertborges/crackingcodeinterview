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

void sumLinkedLists(list<int>& ll1, list<int>& ll2)
{
  list<int>::iterator iter1 = ll1.begin();
  list<int>::iterator iter2 = ll2.begin();

  while(iter1 != ll1.end() || ll)
    }

int main(int argc, const char * argv[]) {
  list<int> ll1;
  list<int> ll2;
  ll1.push_back(7);
  ll1.push_back(1);
  ll1.push_back(6);
  ll2.push_back(5);
  ll2.push_back(9);
  ll2.push_back(2);

  printlinkedlist(ll1);
  printlinkedlist(ll2);

  partition(ll, 8);

  printlinkedlist(ll);



  return 0;
}



