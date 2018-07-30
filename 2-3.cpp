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
  int value;
  Node* next;
};

void printLinkedList(Node* head)
{
  while(head->next != nullptr)
  {
    cout << head->value;
    
    if(head->next != nullptr && head->next->next != nullptr)
      cout << "->";
    
    head = head->next;
  }
  
  cout << endl;
}

void removeMiddleNode(Node* middle)
{
  middle->value = middle->next->value;
  middle->next = middle->next->next;
}

int main(int argc, const char * argv[]) {
  Node n1;
  n1.value = 5;
  Node n2;
  n2.value = 7;
  Node n3;
  n3.value = 8;
  Node n4;
  n4.value = 10;
  Node n5;
  n5.value = 8;
  Node n6;
  n6.value = 4;
  
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;
  n5.next = &n6;
  n6.next = nullptr;
  
  printLinkedList(&n1);
  
  removeMiddleNode(&n3);
  
  printLinkedList(&n1);
  
  return 0;
}



