#include <iostream>
#include <algorithm>

using namespace std;

//Implement an algorithm to detect if the string has all unique characters. 
bool uniqueCharactersDataStruct(const char* strIn){
	bool checkArray[255];
	//Initialize the checking array to be all false from the start.
	for(int i = 0; i < 255; i++){
		checkArray[i] = false;
	}
	//Go through the input string and set checkArray[char] to be true when 
	//char is found in the input string.
	for(const char* strPtr = strIn; *strPtr != '\0'; ++strPtr){
		//If checkArray at a certain character is already true, then
		//it means that we encountered that char somewhere, so return false.
		if(checkArray[*strPtr]) return false;
		checkArray[*strPtr] = true;
	}
	return true;
}
//What if you can't use additional data structures?
bool uniqueCharacters(char* strIn){
	//Sort the given string:
	//NOTE: If this function had a const input, then 
	//a new string would have to be made with strcpy in order
	//to sort it.
	char* strInEnd = strIn;
	//Get to end of strIn
	while(strInEnd) ++strInEnd;
	sort(strIn, strInEnd);
	//Now that the string is sorted, we can simply go through it and check
	//whether neighboring elements are the same.
	char currElt = *strIn;
	for(strIn + 1; *strIn && currElt; ++strIn){
		if(*strIn == currElt) return false;
		currElt = *strIn; 
	}
	return true;
}

int main(){
	//uniqueCharactersDataStruct tests:
	cout << "uniqueCharactersDataStruct tests:" << endl;
	cout << uniqueCharactersDataStruct("") << endl;
	cout << uniqueCharactersDataStruct("a") << endl;
	cout << uniqueCharactersDataStruct("abcdefghijklmnopqrstu.") << endl;
	cout << uniqueCharactersDataStruct("abcdefghajklmnopqrstu.") << endl;
	cout << uniqueCharactersDataStruct("baaaaaaa") << endl;
	//uniqueCharacters tests:
	cout << "uniqueCharacters tests: " << endl;
	cout << uniqueCharactersDataStruct("") << endl;
	cout << uniqueCharactersDataStruct("a") << endl;
	cout << uniqueCharactersDataStruct("abcdefghijklmnopqrstu.") << endl;
	cout << uniqueCharactersDataStruct("abcdefghajklmnopqrstu.") << endl;
	cout << uniqueCharactersDataStruct("baaaaaaa") << endl;
	return 0;
}