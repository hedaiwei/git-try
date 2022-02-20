************** water Area ************
===========solution 1=================
#include <vector>
using namespace std;

int waterArea(vector<int> heights) {
	vector<int> maxes( heights.size() , 0);
	int leftMax = 0;
	for( int i = 0; i < heights.size() ; i++){
		int height = heights[i];
		maxes[i] = leftMax;
		leftMax = max(leftMax,height);
	}
	int rightMax = 0;
	for( int i = heights.size() -1; i >= 0; i--){
		int height = heights[i];
		int minHeight = min( rightMax , maxes[i] );
		if( height < minHeight){
			maxes[i] = minHeight - height ;
		}else {
			maxes[i ] = 0;
		}
		rightMax = max(rightMax , height);
	}
	int total = 0;
	for( int i = 0; i < heights.size() ; i++){
		total += maxes[i];
	}
	return total;
}
============= solution 2 ===============
#include <vector>
using namespace std;

int waterArea(vector<int> heights) {
  if( heights.size() == 0){ return 0; }
	int leftIdx = 0;
	int rightIdx = heights.size() - 1;
	int leftMax = heights[ leftIdx ];
	int rightMax = heights[ rightIdx ];
	int surfaceArea = 0;
	while( leftIdx < rightIdx ){
		if( heights[ leftIdx ] < heights[ rightIdx ] ){
			leftIdx++;
			leftMax = max( leftMax , heights[ leftIdx ] );
			surfaceArea += leftMax - heights[ leftIdx ];
		}else{
			rightIdx--;
			rightMax = max( rightMax , heights[ rightIdx ] );
			surfaceArea += rightMax - heights[ rightIdx ];
		}
	}
	return surfaceArea;
}
