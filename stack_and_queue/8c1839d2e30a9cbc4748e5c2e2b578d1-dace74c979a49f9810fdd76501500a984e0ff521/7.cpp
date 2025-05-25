#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

int main() {

	string buf;
	getline(cin, buf);
	istringstream istr(buf);

	queue<string> players;
	while(istr >> buf)
		players.push(buf);

	int moves;
	cin >> moves;

	int remainingMoves = moves;
	while(players.size() > 1) {

		string curPlayer = players.front(); players.pop();
		remainingMoves--;

		if (remainingMoves == 0) {
			// the players exists the game
			cout << "Removed " << curPlayer << endl;
			remainingMoves = moves;
		} else {
			players.push(curPlayer);
		}
	}

	cout << "Last is " << players.front() << endl;

	return 0;
}

/*
Lucas Jacob Noah Logan Ethan
10

10 => 9  Noah Logan Ethan Lucas
9 => 8 Noah Logan Ethan Lucas Jacob
8 => 7 Logan Ethan Lucas Jacob Noah
7 => 6 Ethan Lucas Jacob Noah Logan 
6 => 5 Lucas Jacob Noah Logan Ethan 
..
1 => 0 Lucas Jacob Noah Logan 

*/