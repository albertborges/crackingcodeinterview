#include <iostream>
using namespace std;

void stepcount( int n, int* arr )
{
  if( n == 0 )
    return;
  
  if( arr[n] == 0 )
  {
    if( arr[n-1] == 0 )
      stepcount(n-1, arr);
    if( arr[n-2] == 0 )
      stepcount(n-2, arr);
    if( arr[n-3] == 0 )
      stepcount(n-3, arr);
    arr[n] = arr[n-3] + arr[n-2] + arr[n-1];
  }
}

int stepcount( int numsteps )
{
  // base cases
  if( numsteps <= 0 )
    return 0;
  
  if( numsteps == 1 )
    return 1;
  
  int steparr[numsteps+1];
  steparr[0] = 0;
  steparr[1] = 1;
  steparr[2] = 2;
  
  for( int i = 3; i <= numsteps; i++ )
    steparr[i] = 0;
  
  stepcount( numsteps, steparr );
  
  return steparr[numsteps];
}

int main () {
  cout << stepcount(4) << endl;
  return 0;
}
