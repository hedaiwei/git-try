************** Apartment Hunting ****************
=========== solution 1 ==================

#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

int distanceBetween(int a,int b){ return abs(a-b); }

int getIdxAtMinValue(vector<int> array){
	int idxAtMinValue = 0;
	int minValue = INT_MAX;
	for (int i = 0 ; i < array.size(); ++i ){
		int currentValue = array[i];
		if(currentValue < minValue ){
			minValue = currentValue;
			idxAtMinValue = i;
		}
	}
	return idxAtMinValue;
}
int apartmentHunting(vector<unordered_map<string, bool>> blocks,
                     vector<string> reqs) {
  vector<int> maxDistancesAtBlocks(blocks.size(), INT_MIN);
	for(int i = 0; i < blocks.size();++i){
		for(auto req : reqs){
			int closestReqDistance = INT_MAX;
			for(int j = 0; j < blocks.size(); ++j){
				if(blocks[j][req]){
					closestReqDistance = min(closestReqDistance,distanceBetween(i,j));
				}
			}
			maxDistancesAtBlocks[i] = max(maxDistancesAtBlocks[i],closestReqDistance);
		}
		
	}
  return getIdxAtMinValue(maxDistancesAtBlocks);
}
=================solution 2 ==============================
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

int distanceBetween(int a,int b){ return abs(a-b); }

int getIdxAtMinValue(vector<int> array){
	int idxAtMinValue = 0;
	int minValue = INT_MAX;
	for (int i = 0 ; i < array.size(); ++i ){
		int currentValue = array[i];
		if(currentValue < minValue ){
			minValue = currentValue;
			idxAtMinValue = i;
		}
	}
	return idxAtMinValue;
}

vector<int> getMaxDistancesAtBlocks( vector<unordered_map<string, bool>> blocks,
																	 	vector<vector<int>> minDistancesFromBlocks ){
	vector<int> maxDistancesAtBlocks( blocks.size() );
	for( int i = 0 ; i < blocks.size() ; i++ ){
		vector<int> minDistancesAtBlock;
		for( auto distances : minDistancesFromBlocks ){
			minDistancesAtBlock.push_back( distances[i] );
		}
		maxDistancesAtBlocks[i] = *max_element( minDistancesAtBlock.begin() , minDistancesAtBlock.end() );
	}
	return maxDistancesAtBlocks;
}
vector<int> getMinDistances( vector<unordered_map< string, bool >> blocks ,
													 	string req ) {
	vector<int> minDistances( blocks.size() );
	int closestReqIdx = INT_MAX;
	for( int i = 0; i < blocks.size() ; i++ ){
		if( blocks[i][req] ){
			closestReqIdx = i;
		}
		minDistances[i] = distanceBetween( i , closestReqIdx );
	}
	for( int i = blocks.size()-1 ; i >= 0 ; i-- ){
		if( blocks[i][req] ){
			closestReqIdx = i;
		}
		minDistances[i] = min( minDistances[i], distanceBetween( i , closestReqIdx ) );
	}
	return minDistances;
}

int apartmentHunting(vector<unordered_map<string, bool>> blocks,
                     vector<string> reqs) {
  vector<vector<int>> minDistancesFromBlocks;
	for( string req : reqs ){
		minDistancesFromBlocks.push_back( getMinDistances( blocks , req ) );
	}
	vector<int> maxDistancesAtBlocks = getMaxDistancesAtBlocks( blocks , minDistancesFromBlocks );
  return getIdxAtMinValue( maxDistancesAtBlocks );
}



