************ validate subsequence *************
================ solution 1 ===============
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  int arrIdx = 0;
	int seqIdx = 0;
	while( arrIdx < array.size() && seqIdx < sequence.size() ){
		if( array[ arrIdx ] == sequence[ seqIdx ] ){
			seqIdx++;
		}
		arrIdx++;
	}
  return seqIdx == sequence.size() ;
}
=============== solution 2 ===============
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  int seqIdx = 0; 
	for( auto value : array ){
		if( seqIdx == sequence.size() ){
			break;
		}
		if( sequence[ seqIdx ] == value ){
			seqIdx ++;
		}
	}
  return seqIdx == sequence.size() ;
}

