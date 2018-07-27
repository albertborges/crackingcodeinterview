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

// O(n), where n is the number of characters in both str1 and str2
bool isPerm( string str1, string str2 )
{
	unordered_map<char, int> characters;
	for(int i=0; i<str1.length(); i++)
	{
		if(characters.find(str1[i]) == characters.end())
		characters[str1[i]] = 1;
		else
		characters[str1[i]]++;
	}

	for(int i=0; i<str2.length(); i++)
	{
		if(characters.find(str2[i]) == characters.end())
		return false;
		else
		characters[str2[i]]--;
	}

	unordered_map<char, int>::iterator itr;
	for(itr=characters.begin(); itr!=characters.end(); itr++)
	{
		if(itr->second != 0)
		return false;
	}
	return true;
}

int main(int argc, const char * argv[]) {
	string str1("abcd");
	string str2("cba");
	printf("%d\n", isPerm(str1,str2));
	return 0;
}

