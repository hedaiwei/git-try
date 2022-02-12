************ NumberOfWaysToMakeChange **********
=============solution 1 =================
#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
	vector<int> ways(n+1 , 0 );
	ways[0] = 1;
	for( int denom : denoms ){
		for( int amount = 1; amount < n+1 ; amount++ ){
			if( denom <= amount ){
				ways[ amount ] += ways[ amount  - denom ]; 
			}
		}
	}
	return  ways[ n ];
}
************ Max Subset Sum No Adjacent ************
============= solution 1 =================
#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
  if( array.size() == 0 ) { return 0; }
	else if( array.size() == 1){ return array[0]; }
	vector<int> maxSums = array;
	maxSums[1] = max(array[0],array[1]);
	for( int i = 2; i < array.size(); ++i ){
		maxSums[i] = max( maxSums[i-1], maxSums[i-2] + array[i]);
	}
  return maxSums[ array.size() - 1 ] ;
}
