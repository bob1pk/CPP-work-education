#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

void printQueue(priority_queue<int> queue) {
	cout << "Queue is: ";
	while(queue.size()) {
		cout << queue.top() << " ";
		queue.pop();
	}
	cout << endl;
}

int main() {

	const int data[] = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};

    std::priority_queue<int> pq;

    // Fill the priority queue.
    for (int n : data) {
        pq.push(n);
		printQueue(pq);
	}


	return 0;
}
