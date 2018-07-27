#include <iostream>
#include <vector>
using namespace std;

vector<int> convertVectorToArray( int arr[], int size )
{
  vector<int> vec;
  for( int i = 0; i < size; i++ )
    vec.push_back( arr[i] );
  
  return vec;
}

void printVector( const vector<int> vec )
{
  cout << "{";
  for(int i = 0; i<vec.size(); i++)
  {
    cout << vec[i];
    
    if( i != vec.size() - 1 )
      cout << ",";
  }
  cout << "}" << endl;
}

void printVector( const vector< vector<int> >& vec )
{
  for(int i = 0; i<vec.size(); i++)
  {
    printVector(vec[i]);
  }
}

void printSubsets( int** sets )
{
  //  for( int i = 0; )
}



void getAllSubsets( vector<int> vecin, vector< vector<int> >& subsets, int index )
{
  if( index == -1 )
  {
    vector<int> emptysubset;
    subsets.push_back( emptysubset );
  }
  else
  {
    vector< vector<int> > newsubsets;
    // Add int at index in vecin to all the subsets
    for( int i = 0; i < subsets.size(); i++ )
    {
      vector<int> newsubset = subsets[i];
      newsubset.push_back(vecin[index]);
      newsubsets.push_back(newsubset);
    }
    subsets.insert(subsets.end(), newsubsets.begin(), newsubsets.end());
  }
  
  index++;
  if( index < (int)vecin.size() )
    getAllSubsets(vecin, subsets, index );
}

int main () {
  int set0[1] = { 0 };
  int set1[2] = { 1, 0 };
  int set2[3] = { 1, 2, 0 };
  int set3[4] = { 1, 2, 3, 0 };
  
  vector<int> vecin = convertVectorToArray( set3, 3 );
  
  vector< vector<int> > subsets;
  getAllSubsets( vecin, subsets, -1 );
  
  cout << subsets.size() << endl;
  
  printVector(subsets);
  
  return 0;
}

