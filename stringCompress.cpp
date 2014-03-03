#include <iostream>
#include <string>
//NOTE: uses C++11 function to_string(int)
using namespace std;

//Implement a method to perform basic string compression using the counts
//of repeated characters. For example, the string aabcccccaaa would become
//a2blc5a3. If the "compressed" string would not become smaller than the orig-
//inal string, your method should return the original string.
string stringCompress(const string& strIn){
	int originalSize = strIn.size();
	string strNew;
	//Start with a character, send a walker to check how many
	//characters of same type there are in a sequence, remove those chars,
	//and insert the resulting count into the string.
	for(int i = 0; i < originalSize; i++){
		int j = i;
		while((j < originalSize) && (strIn[j] == strIn[i])) j++;
		strNew += strIn[i];
		strNew += to_string(j - i);
		i = j - 1;
	}
	if(strNew.size() < originalSize) return strNew;
	else return strIn;
}

int main(){
	cout << "stringCompress test cases:" << endl;
	cout << stringCompress("") << endl;
	cout << stringCompress("a") << endl;
	cout << stringCompress("aaa") << endl;
	cout << stringCompress("aaaabbbcbaa") << endl;
	cout << stringCompress("aabcccccaaa") << endl;
}