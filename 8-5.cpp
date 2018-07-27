#include <iostream>
#include <vector>
using namespace std;

void recMult( unsigned int& result, unsigned int a, unsigned int b )
{
  if( b==0 )
    return;
  else
    result += a;
  
  recMult(result, a, b-1);
}

int main () {
  unsigned int a = 10;
  
  unsigned int result = 0;
  recMult(result, 11,11);
  cout << result << endl;
  
  return 0;
}
