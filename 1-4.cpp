unordered_map<char, int> characterToCountMap( std::string str )
{
  unordered_map<char, int> map;
  for( int i=0; i<str.length(); i++ )
  {
    if(map.find(str[i]) != map.end())
      map[str[i]]++;
    else
      map[str[i]] = 1;
  }
  
  return map;
}

bool isPalindromePermutation( std::string str )
{
  // Acquire the character map
  unordered_map<char, int> map = characterToCountMap(str);
  
  // If it is even, then all the character counts must map to even values
  // Else if it odd, there can be one character count with an odd value
  bool fEven = str.length() % 2 == 0;
  int oddCount = 0;
  
  unordered_map<char, int>::iterator iter;
  for(iter=map.begin(); iter!=map.end(); iter++)
  {
    bool fCurrOdd = iter->second % 2 != 0;
    if(fEven && fCurrOdd)
      return false;
    else if(!fEven && fCurrOdd)
    {
      oddCount++;
      if( oddCount > 1 )
        return false;
    }
  }
  
  return fEven || (!fEven && oddCount == 1);
}

int main(int argc, const char * argv[]) {
  std::string str("tactcoa");
  printf("%i", isPalindromePermutation(str));
  return 0;
}
s
