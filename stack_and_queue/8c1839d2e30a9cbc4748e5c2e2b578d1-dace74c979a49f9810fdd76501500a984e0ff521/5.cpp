#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

int main() {

	string buffer;
	getline(cin, buffer);

	istringstream istr(buffer);

	queue<int> qu;
	int curr;
	while(istr >> curr)
		qu.push(curr);

	bool bFirst = true;
	while(qu.size()){
		int front = qu.front(); qu.pop();
		if (front % 2 == 0) {
			if (bFirst)
				bFirst = false;
			else
				cout << ", "; 
			cout << front;
		}
	}

	cout << endl;

	return 0;
}
