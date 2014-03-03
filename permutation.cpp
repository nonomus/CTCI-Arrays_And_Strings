#include <iostream>

using namespace std;

//Given two strings, write a method to decide whether one
//is a permutation of the other.
bool isPermutation(const char* str1, const char* str2){
	int str1Composition[255] = {0};
	int str2Composition[255] = {0};
	//First, fill up the two arrays by going thru str1 and
	//str2 and incrementing every element char as we encounter it.
	while(*str1){
		str1Composition[*str1]++;
		++str1;
	}
	while(*str2){
		str2Composition[*str2]++;
		++str2;
	}
	for(int i = 0; i < 255; i++){
		if(str1Composition[i] != str2Composition[i]) return false;
	}
	return true;
}

int main(){
	//permutation test cases:
	cout << "permutation test cases:" << endl;
	cout << isPermutation("", "") << endl;
	cout << isPermutation("", "a") << endl;
	cout << isPermutation("abc", "cba") << endl;
	cout << isPermutation("one", "two") << endl;
	return 0;
}