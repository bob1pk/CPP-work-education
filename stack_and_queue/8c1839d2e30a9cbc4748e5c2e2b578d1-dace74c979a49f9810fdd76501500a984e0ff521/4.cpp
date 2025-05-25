#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int main() {

	string buf;
	getline(cin, buf);

	// "1 + (2 - (2 + 3) * 4 / (3 + 1)) * 5"
	stack<size_t> openBrackets;

	for(size_t curCharIdx = 0; curCharIdx < buf.size(); curCharIdx++) {

		switch(buf[curCharIdx]) {
			case '(':
				openBrackets.push(curCharIdx);
				break;
			case ')':
				size_t lastOpenBracketIdx = openBrackets.top(); openBrackets.pop();
				string subStr = buf.substr(lastOpenBracketIdx, curCharIdx - lastOpenBracketIdx + 1);
				cout << subStr << endl;
				break;
		}
	}

	return 0;
}
