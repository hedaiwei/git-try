************* longest common subsequence ************
============== solution 1 ====================
#include <vector>
using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2) {
  vector<vector<vector<char>>> lcs;
	for( int i = 0; i < str2.length() + 1; i++){
		lcs.push_back( vector<vector<char>>() );
		for( int j = 0; j < str1.length() + 1; j++){
			lcs[i].push_back( vector<char>() );
		}
	}
	for( int i = 1; i < str2.length() + 1; i++){
		for( int j = 1; j < str1.length() + 1; j++){
			if( str2[ i -1 ] == str1[ j-1 ] ){
				vector<char> copy = lcs[ i-1 ][ j-1 ];
				copy.push_back( str2[ i -1 ] );
				lcs[i][j] = copy;
			}else{
				lcs[i][j] = lcs[ i-1 ][ j ].size() > lcs[i][ j-1 ].size() ? lcs[i-1][j] : lcs[i][j-1];
			}
		}
	}
  return lcs[ str2.length() ][ str1.length() ];
}

============== solution 2 ====================
--- 如果没有长度+1 ( 有个初始行 ) 会导致j-1 第一次为-1 产生访问错误  -------
#include <vector>
using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2) {
	string small = str1.length() < str2.length() ? str1 : str2;
	string big = str1.length() >= str2.length() ? str1 : str2;
	vector<vector<char>> evenLcs;
	vector<vector<char>> oddLcs;
	for( int i = 0; i < small.length()+1 ; i++ ){
		evenLcs.push_back( vector<char>() );
		oddLcs.push_back( vector<char>() );
	}
	for( int i = 1; i < big.length() + 1; i++ ){
		vector<vector<char>> *currentLcs;
		vector<vector<char>> *previousLcs;
		if( i % 2 == 1){
			currentLcs = &oddLcs;
			previousLcs = &evenLcs;
		}else {
			currentLcs = &evenLcs;
			previousLcs = &oddLcs;
		}
		for( int j = 1 ; j < small.length() + 1; j++ ){
			if( big[ i-1 ] == small[ j-1 ] ){
				vector<char> copy = previousLcs->at(j-1);
				copy.push_back( big[i-1] );
				currentLcs->at(j) = copy;
			}else{
				currentLcs->at(j) = 
					previousLcs->at(j).size() > currentLcs->at( j-1 ).size()
					? previousLcs->at(j) : currentLcs->at(j-1);
			}
		}
	}
	return big.length() % 2 == 0 ? evenLcs[ small.length() ]: oddLcs[ small.length() ];
}
=============== solution 3 ==================
#include <vector>
using namespace std;

vector<char> buildSequence( vector<vector<vector<int>>> lcs ){
	vector<char> sequence;
	int i = lcs.size() - 1;
	int j = lcs[0].size() -1;
	while( i != 0 && j != 0 ){
		vector<int> currentEntry = lcs[i][j];
		if( currentEntry[0] != -1 ){
			sequence.insert( sequence.begin() , currentEntry[0] );
		}
		i = currentEntry[2];
		j = currentEntry[3];
	}
	return sequence;
}


vector<char> longestCommonSubsequence(string str1, string str2) {
	vector<vector<vector<int>>> lcs( str2.length() + 1, vector<vector<int>>( str1.length() + 1, vector<int>( 4,0 ) ) );
	for( int i = 1; i < str2.length() + 1; i++ ){
		for( int j = 1; j < str1.length() + 1; j++ ){
			if( str2[ i-1 ] == str1[ j-1 ] ){
				lcs[i][j] = { str2[ i-1 ], lcs[ i-1 ][ j-1 ][ 1 ]+ 1 , i -1 , j -1 };
			}else{
				if( lcs[ i-1 ][ j ][ 1 ] > lcs[ i ][ j-1 ][ 1 ] ){
					lcs[i][j] = { -1 , lcs[ i-1 ][ j ][ 1 ] , i-1 , j };
				}else {
					lcs[i][j] = { -1 , lcs[ i ][ j-1 ][ 1 ] , i , j-1 };
				}
			}
		}
	}
  return buildSequence( lcs );
}
============ solution 4 ================
#include <vector>
using namespace std;

vector<char> buildSequence( vector<vector<int>> lengths, string str){
	vector<char> sequence;
	int i = lengths.size() -1;
	int j = lengths[0].size() -1;
	while( i != 0 && j != 0 ){
		if( lengths[i][j] == lengths[ i-1 ][j] ){
			i--;
		}else if( lengths[i][j] == lengths[i][ j-1 ] ){
			j--;
		}else {
			sequence.insert( sequence.begin() , str[ j-1 ] );
			i--;
			j--;
		}
	}
	return sequence;
}

vector<char> longestCommonSubsequence( string str1, string str2 ){
	vector<vector<int>> lengths( str2.length() + 1, vector<int>( str1.length() + 1, 0 ) );
	for( int i = 1; i < str2.length() + 1; i++){
		for( int j = 1; j < str1.length() + 1; j++){
			if( str2[ i-1 ] == str1[ j-1 ] ){
				lengths[i][j] = lengths[i-1][j-1]+1;
			}else{
				lengths[i][j] = max( lengths[ i-1 ][j] , lengths[i][ j-1 ] );
			}
		}
	}
	return buildSequence( lengths , str1 );
}



