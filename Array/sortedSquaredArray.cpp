*********** sorted square array ***********
==============solution 1 ================
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  vector<int> sortedSquares( array.size() , 0 );
	for( int idx = 0; idx < array.size() ; idx++ ){
		int value = array[idx];
		sortedSquares[ idx ] = value * value;
	}
	sort( sortedSquares.begin() , sortedSquares.end() );
  return sortedSquares;
}
===========solution 2===============
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  vector<int> sortedSquares( array.size() , 0 );
	int smallerValueIdx = 0;
	int largerValueIdx = array.size() - 1;
	for( int idx = array.size()-1 ; idx >= 0; idx-- ){
		int smallerValue = array[ smallerValueIdx ];
		int largerValue = array[ largerValueIdx ];
		if( abs( smallerValue ) > abs( largerValue ) ){
			sortedSquares[ idx ] = smallerValue * smallerValue;
			smallerValueIdx++;
		}else{
			sortedSquares[idx] = largerValue * largerValue;
			largerValueIdx--;
		}
	}
  return sortedSquares;
}
