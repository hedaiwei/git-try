************** twoNumberSum ****************
==================solution 2======================

#include <vector>
#include <unordered_set>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  unordered_set<int> nums;
	for( int num : array ){
		int potentialMatch = targetSum - num;
		if( nums.find(potentialMatch) != nums.end() ){
			return vector<int>{ potentialMatch , num };
		}else {
			nums.insert(num);
		}
	}
  return {};
}
=================solution 3 ====================
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  sort( array.begin() , array.end() );
	int left = 0;
	int right = array.size() -1;
	while( left < right ){
		int currentSum = array[ left ] + array[ right ];
		if( currentSum == targetSum ){
			return { array[left] , array[right] };
		}else if( currentSum < targetSum ) {
			left++;
		}else { 
			right--;
		}
	}
  return {};
}
