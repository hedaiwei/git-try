************** LevenShteinDistance **************
==================solution 1=====================
#include <vector>
using namespace std;

int levenshteinDistance(string str1, string str2) {
	vector< vector<int> > edits( str2.length() + 1 , vector<int>( str1.length() + 1 ,0 ) );
	for( int i = 0; i < str2.length( ) + 1; i++ ){
		for( int j = 0; j < str1.length() + 1; j++ ){
			edits[i][j] = j;
		}
		edits[i][0] = i;
	}
	for( int i = 1; i < str2.length() + 1 ; i++ ){
		for( int j = 1; j< str1.length() + 1; j++ ){
			if( str2[i - 1] == str1[j -1] ){
				edits[ i ][ j ] = edits[ i - 1 ][ j - 1 ];
			}else {
				edits[i][j] = 1 + min( edits[i-1][j-1] , min( edits[i-1][j], edits[i][j-1] ) );
			}
		}
	}
	return edits[str2.length()][str1.length()];
}

==================solution 2=====================
using namespace std;

int levenshteinDistance(string str1, string str2) {
	string small = str1.length() < str2.length() ? str1 : str2;
	string big = str1.length() >= str2.length() ? str1 : str2;
	vector<int> evenEdits( small.length() + 1);
	vector<int> oddEdits( small.length() + 1);
	for( int j = 0; j< small.length() + 1; j++ ){
		evenEdits[j] = j;
	}
	vector<int> *currentEdits;
	vector<int> *previousEdits;
	for(int i = 1; i < big.length() + 1; i++ ){
		if( i % 2 == 1 ){
			currentEdits = &oddEdits;
			previousEdits = &evenEdits;
		}else{
			currentEdits = &evenEdits;
			previousEdits = &oddEdits;
		}
		(*currentEdits)[0] = i;
		for( int j = 1; j < small.length() + 1 ; j++){
			if( big[ i-1 ] == small[ j-1 ] ){
				(*currentEdits)[j] = previousEdits->at( j-1 );
			}else{
				(*currentEdits)[j] = 1+min(previousEdits->at(j-1), min(previousEdits->at(j),currentEdits->at(j-1)) );
			}
		}
	}
	return big.length() % 2 == 0 ? evenEdits[ small.length() ] : oddEdits[ small.length() ];
}
