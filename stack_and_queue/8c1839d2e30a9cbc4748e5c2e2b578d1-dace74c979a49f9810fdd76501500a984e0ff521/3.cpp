#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int main() {

	string buf;
	getline(cin, buf);

	istringstream expr(buf);
	stack<int> digits;
	stack<char> operations;

	int digit;
	while(expr >> digit) {		
		digits.push(digit);
		
		char oper;
		if (expr >> oper)
			operations.push(oper);
		else
			break;
	}

	// 2 + 5 + 10 - 2 - 1
	int sum = 0;

	while(operations.size()) {
		char op = operations.top(); operations.pop();
		int arg = digits.top(); digits.pop();
		
		if (op == '-')
			sum -= arg;
		else
			sum += arg;
	}

	if (digits.size())
		sum += digits.top();

	cout << sum << endl;

	return 0;
}
