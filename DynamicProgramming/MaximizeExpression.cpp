********** MaximizeExpression ************
===========solution 1============
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
int evaluateExpression( int a,int b,int c,int d){ return a-b+c-d; }
int maximizeExpression(vector<int> array) {
	if( array.size() < 4) { return 0; }
	int maximumValueFound = numeric_limits<int>::min();
	for( int a = 0; a < array.size() ; a++){
		int aValue = array[a];
		for( int b = a+1; b < array.size(); b++){
			int bValue = array[b];
			for( int c = b+1; c < array.size() ; c++){
				int cValue = array[c];
				for( int d = c+1; d< array.size() ; d++){
					int dValue = array[d];
					int expressionValue = evaluateExpression( aValue, bValue,cValue,dValue);
					maximumValueFound = max( expressionValue, maximumValueFound);
				}
			}
		}
	}
	return maximumValueFound;
}
=========solution 2==========
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int maximizeExpression(vector<int> array) {
  if( array.size() < 4) { return 0; }
	vector<int> maxOfA = { array[0] };
	vector<int> maxOfAMinusB = { numeric_limits<int>::min() };
	vector<int> maxOfAMinusBPlusC( 2 ,numeric_limits<int>::min() );
	vector<int> maxOfAMinusBPlusCMinusD( 3, numeric_limits<int>::min() );
	for( int idx = 1; idx < array.size() ; idx++){
		int currentMax = max( maxOfA[ idx-1 ], array[ idx ] );
		maxOfA.push_back( currentMax );
	}
	for( int idx = 1; idx < array.size(); idx++ ){
		int currentMax = max( maxOfAMinusB[ idx-1 ] , maxOfA[ idx-1 ] - array[ idx ] );
		maxOfAMinusB.push_back( currentMax );
	}
	for( int idx = 2; idx < array.size(); idx++ ){
		int currentMax = max( maxOfAMinusBPlusC[ idx-1 ], maxOfAMinusB[ idx-1 ] + array[ idx ] );
		maxOfAMinusBPlusC.push_back( currentMax );
	}
	for( int idx = 3; idx < array.size(); idx++ ){
		int currentMax = max( maxOfAMinusBPlusCMinusD[ idx-1 ], maxOfAMinusBPlusC[ idx-1 ] - array[ idx ] );
		maxOfAMinusBPlusCMinusD.push_back( currentMax );
	}
  return maxOfAMinusBPlusCMinusD[ maxOfAMinusBPlusCMinusD.size()-1 ];
}
