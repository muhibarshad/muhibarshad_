#include <iostream>
#include <string>

using namespace std ; 
int ArrayChallenge(int arr[], int arrLength)
{
	
	int highest_sum = arr[0];
	int current_sum = arr[0];
	
	for(int i = 0 ; i< arrLength ; i++)
	{
		current_sum = max(arr[i] , current_sum + arr[i]);
		highest_sum = max(highest_sum , current_sum );
	}
	
	return highest_sum ;
}

string MathChallenge(string str){
	
	int n = str.length();
	
	if(str.length() == 1 )
		return "-1";
		
	for( int len = 1 ; len <= n/2 ; ++len )	
	{
		string candidate =  str.substr(0,len) ;
		int repeatition = n/len ;
		
		string repeatedCandidate = "";
		for(int i = 0 ; i < repeatition ; ++i )
			repeatedCandidate += candidate ;
		
		if( repeatedCandidate == str)
			return candidate ;
	}
	
	return "-1";
}

int main(){
	
	int arr[] = {1,2,-3,-4,5,6,-1,5,2,-3,-9,6};
	//int arr[] = {-2 , 5 , -1 , 7 , -3 };
//	int arr[] = { 1 , -2 , 0 , 3 };
//	int arr[] = { 3 , -1 , -1 , 4 , 3 , -1 };
	int arrLength = sizeof(arr) / sizeof(*arr) ;
	
	cout << ArrayChallenge(arr , arrLength)<< endl << endl << endl;
	
//	cout << MathChallenge("abcababcababcab") << endl;
//    cout << MathChallenge("abababababab" ) << endl;
    
	return 0 ;
}
