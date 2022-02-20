*************** min Number of Jumps *******************
=============solution 1==================
#include <vector>
#include <climits>
using namespace std;

int minNumberOfJumps(vector<int> array) {
	vector<int> jumps(array.size(), INT_MAX);
	jumps[0] = 0;
	for( int i = 1; i < array.size() ; i++){
		for( int j = 0; j < i; j++){
			if( array[j ] >= i-j ){
				jumps[i ] = min(jumps[j] + 1, jumps[i] );
			}
		}
	}
	return jumps[ jumps.size() -1 ];
}
=============solution 2=================
#include <vector>
using namespace std;

int minNumberOfJumps(vector<int> array) {
  if( array.size() == 1 ){ return 0; }
	int jumps = 0;
	int maxReach = array[0];
	int steps = array[0];
	for( int i = 1; i < array.size() -1; i++){
		maxReach = max( maxReach , i+array[i]);
		steps--;
		if( steps == 0 ){
			jumps++;
			steps = maxReach - i;
		}
	}
  return jumps + 1;
}


