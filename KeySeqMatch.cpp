/*
This is to demonstrate how to find the repeated key sequences inside input stream
more efficiently. It can be used widely in various applications.

The input is a decimal data stream and the program trys to find all repeated
sequences that are 10-digit long. For example:

The input string:
      1111199999111119999991111122222333

will return:
      1111199999,   9999911111

The algorithm is based on hash-table and "sliding-windows". The function defines 
a window of length of 10-characters. Then it slides the window along the input
stream, calculates the hash-key used in key matching. At the end the function 
returns the data sequences found.

To be concise, the function is implemented with bit-operation and STL. It has
been compiled with C++11 compiler.
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>

#define bitnum  4
#define bitmask 0xF
#define keylength 10

using namespace std;

vector<string> findKeySeq(string s) {
    unordered_map<int, int> uomap;
    vector<string> res;
    vector<string>::const_iterator cii;

    int temp = 0, i = 0, ss = s.size();
    while (i < 9) {
        temp = temp << bitnum | s[i++] & bitmask;
    }
    while (i < ss) {
        if (uomap[temp = temp << bitnum & 0xFFFFFFFFFF | s[i++] & bitmask]++ == 1) {
            res.push_back(s.substr(i - 10, 10));
		}
	}

	// Output the result before return
   	for(cii=res.begin(); cii!=r.end(); cii++)
   	{
    	cout << *cii << endl;
   	}		

    return res;
}

int main() {
	string line;
	string data;
	vector<string> res;

	// Read data in. This is just for reading small files
	ifstream myfile ("inputdata.txt");
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			cout << line << '\n';
			data.append(line);
		}
		cout << "input data: " << endl << data;
    	myfile.close();
		findKeySeq(data);
    } else {
		cout << "Unable to open file"; 
  	}

	return 0;	
}

