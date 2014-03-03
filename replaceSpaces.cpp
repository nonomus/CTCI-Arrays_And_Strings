#include <iostream>
#include <cstring>

using namespace std;

//Write a method to replace all spaces in a string with'%20'. You may assume that
//the string has sufficient space at the end of the string to hold the additional
//characters, and that you are given the "true" length of the string. 
//Note: nullchar is included in true size.
void replaceSpace(char* str, int trueSize){
	//Count the number of spaces in str.
	int numSpaces = 0;
	for(char* strPtr = str; strPtr < str + trueSize; strPtr++){
		if(*strPtr == ' ') numSpaces++;
	}
	//The size of the new string must then be trueSize (original string with
	//one character/space) + numSpaces (additional 2 characters/space)
	char newStr[trueSize + numSpaces * 2];
	//Go through input string str and copy new values into newStr with
	//'%20' replacing ' '.
	char* cpPtr = newStr;
	for(char* strPtr = str; strPtr < str + trueSize; strPtr++, cpPtr++){
		if(*strPtr == ' '){
			*cpPtr++ = '%';
			*cpPtr++ = '2';
			*cpPtr = '0';
		} 
		else *cpPtr = *strPtr;
	}
	//End the newStr with '\0'
	*cpPtr = '\0';
	//Copy newStr into the original one.
	strcpy(str, newStr);
}


int main(){
	cout << "replaceSpace test cases:" << endl;
	char str1[] = "a b c         ";
	replaceSpace(str1, 6);
	cout << str1 << endl;

	char str2[] = "      ";
	replaceSpace(str2, 1);
	cout << str2 << endl;
	return 0;
}