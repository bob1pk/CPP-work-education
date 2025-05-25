#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main() {

	stack<int> st;

	// read the initial stack - first line of integers
	string buf;
	getline(cin, buf);

	istringstream istr(buf);
	int curr;
	while(istr >> curr)
		st.push(curr);

	// process all commands until we get "end"
	while(true) {
		getline(cin, buf);

		if (buf == "end")
			break;

		istringstream istr(buf);
		string command;
		istr >> command;
		int arg1;
		istr >> arg1;
		
		if (command == "add") {
			int arg2;
			istr >> arg2;
			st.push(arg1);
			st.push(arg2);
		} else { // "remove"

			if (arg1 <= st.size())
				while(arg1) {
					st.pop();
					arg1--;
				}
		}
	}

	// sum all elements
	int sum = 0;
	while(st.size()) {
		sum += st.top();
		st.pop();
	}

	cout << sum << endl;
	return 0;
}
