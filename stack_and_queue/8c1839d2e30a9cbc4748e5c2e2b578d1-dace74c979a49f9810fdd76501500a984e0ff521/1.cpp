#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

	string input;
	getline(cin, input);

	stack<char> st;

	for(char c : input)
		st.push(c);

	while(st.size()) {
		char c = st.top();
		cout << c;
		st.pop();
	}

	cout << endl;

	return 0;
}
