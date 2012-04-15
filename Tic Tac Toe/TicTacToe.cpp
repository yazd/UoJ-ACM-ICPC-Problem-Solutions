#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char checkRow(char board[], unsigned int row) {

	const int ri = row * 3;

	if (board[ri] == board[ri + 1] && board[ri] == board[ri + 2]) return board[ri];
	return '.';

}

char checkColumn(char board[], unsigned int col) {

	if (board[col] == board[col + 3] && board[col] == board[col + 6]) return board[col];
	return '.';

}

int main() {

	ifstream in;
	in.open("tictactoe.in");

	unsigned int test;
	in >> test;

	while (test-- > 0) {

		char board[9];

		for(int i = 0; i < 9; i++) {
			in >> board[i];
		}

		char result = '.';

		for (int i = 0; i < 3; i++) {
			result = checkRow(board, i);
			if (result != '.') goto win;
		}

		for (int i = 0; i < 3; i++) {
			result = checkColumn(board, i);
			if (result != '.') goto win;
		}

		if (board[0] == board[4] && board[0] == board[8]) result = board[0];
		if (result != '.') goto win;

		if (board[2] == board[4] && board[2] == board[6]) result = board[2];
		if (result != '.') goto win;

		cout << "It's a draw.\n";
		goto readGarbage;

		win:
		cout << "Player " << ((result == 'x') ? "1" : "2") << " wins!\n";

		readGarbage:
		in >> board[0];
		in >> board[0];
		in >> board[0];

	}

	return 0;

}

