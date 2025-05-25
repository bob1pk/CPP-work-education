#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

int main() {

	queue<string> customers; // the names of the current customers
	string curr;

	while(true) {

		getline(cin, curr);
		if (curr == "End")
			break;
		else if (curr == "Paid") {
			// print all customers in the queue
			while(customers.size()){
				cout << customers.front() << endl;
				customers.pop();
			}
		} else {
			// it's a customer's name
			customers.push(curr);
		}
	}

	cout << customers.size() << " people remaining." << endl;

	return 0;
}
