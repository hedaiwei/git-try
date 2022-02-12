************ minNumberOfCoinsForChange ***********
=============== solution 1 =================

#include <vector>
#include <climits>

using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
	vector<int> numOfCoins( n+1 , INT_MAX-1 );
	numOfCoins[ 0 ] = 0;
	int toCompare = 0;
	for( int denom : denoms ){
		for( int amount = 0; amount < numOfCoins.size() ; amount++ ){
			if( denom <= amount ){
				//if( numOfCoins[ amount - denom ] == INT_MAX ){
				//	toCompare = numOfCoins[ amount - denom ];
				//}else {
					toCompare = numOfCoins[ amount - denom ] + 1; 
				//}
				numOfCoins[ amount ] = min( numOfCoins[ amount ], toCompare );
			}
		}
	}
	return numOfCoins[ n ] != INT_MAX-1 ? numOfCoins[ n ]: -1 ;
}
