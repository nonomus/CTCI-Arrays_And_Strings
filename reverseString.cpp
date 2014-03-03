#include <iostream>

using namespace std;

//Implement a function void reverse(char* str) which reverses
//a null terminated C string.
void reverse(char* str){
	//Get access to the very end of the string:
	char* end = str;
	char* start = str;
	while(*end) end++;
	//Then set end to be the character right before
	//null char.
	--end;
	while(start <= end){
		char temp = *start;
		*start = *end;
		*end = temp;
		++start;
		--end;
	}

}

int main(){
	//reverse test cases
	cout << "reverese test cases:" << endl;

	char str1[] = "abcdefghijklmnopqrstuv.";
	reverse(str1);
	cout << str1 << endl;

	char str2[] = "";
	reverse(str2);
	cout << str2 << endl;

	char str3[] = "a";
	reverse(str3);
	cout << str3 << endl;
	return 0;
}