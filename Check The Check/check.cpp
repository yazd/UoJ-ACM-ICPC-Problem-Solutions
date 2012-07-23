#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct pos {
  int line;
  int col;
};

int main() {

  int game = 0;

  while (true) {

    //read 8 lines

    string line;
    string board[8];

    pos white_king; //CAPITAL LETTERS, move up
    pos black_king; //small letters, move down

    bool finished = true;

    for (int i = 0; i < 8; i++) {
      getline(cin, line);
      finished = finished && (line == "........");
      board[i] = line;
      for (int j = 0; j < 8; j++) {
        if (line[j] == 'K') {
          white_king.line = i;
          white_king.col = j;
        }
        if (line[j] == 'k') {
          black_king.line = i;
          black_king.col = j;
        }
      }
    }

    if (finished) break;
    getline(cin, line); //read empty line
    game++;

    for (int line = 0; line < 8; line++) {
      for (int col = 0; col < 8; col++) {

        if (board[line][col] == '.') continue;

        if (board[line][col] == 'p') {
          if (white_king.line == line + 1) {
            if ((white_king.col == col - 1) || (white_king.col == col + 1)) goto white_dies;
          }
        }

        if (board[line][col] == 'P') {
          if (black_king.line == line - 1) {
            if ((black_king.col == col - 1) || (black_king.col == col + 1)) goto black_dies;
          }
        }

        if (board[line][col] == 'r' || board[line][col] == 'R') {

          pos opp_king;
          if (board[line][col] == 'r') {
            opp_king = white_king;
          } else {
            opp_king = black_king;
          }

          if (opp_king.line == line) {
            int step = (opp_king.col - col) / abs(opp_king.col - col);
            bool dies = true;
            for (int moved = 1; moved < abs(opp_king.col - col); moved++) {
              int c = opp_king.col - moved * step;
              if (c >= 0 && c < 8)
                dies = dies && (board[line][c] == '.');
            }
            if (dies) goto someone_dies_1;
          }

          if (opp_king.col == col) {
            int step = (opp_king.line - line) / abs(opp_king.line - line);
            bool dies = true;
            for (int moved = 1; moved < abs(opp_king.line - line); moved++) {
              int l = opp_king.line - moved * step;
              if (l >= 0 && l < 8)
                dies = dies && (board[l][col] == '.');
            }
            if (dies) goto someone_dies_1;
          }

          goto check_bishop;

          someone_dies_1:
            if (board[line][col] == 'r') {
              goto white_dies;
            } else {
              goto black_dies;
            }
        }

        check_bishop:
        if (board[line][col] == 'b' || board[line][col] == 'B') {

          pos opp_king;
          if (board[line][col] == 'b') {
            opp_king = white_king;
          } else {
            opp_king = black_king;
          }

          if (abs(opp_king.line - line) == abs(opp_king.col - col)) {
            int lstep = (opp_king.line - line) / abs(opp_king.line - line);
            int cstep = (opp_king.col - col) / abs(opp_king.col - col);
            bool dies = true;
            for (int moved = 1; moved < abs(opp_king.col - col); moved++) {
              int l = opp_king.line - lstep * moved;
              int c = opp_king.col - cstep * moved;
              if (l >= 0 && l < 8 && c >= 0 && c < 8)
                dies = dies && (board[l][c] == '.');
            }
            if (dies) goto someone_dies_2;
          }

          goto check_queen;

          someone_dies_2:
            if (board[line][col] == 'b') {
              goto white_dies;
            } else {
              goto black_dies;
            }
        }

        check_queen:
        if (board[line][col] == 'q' || board[line][col] == 'Q') {

          pos opp_king;
          if (board[line][col] == 'q') {
            opp_king = white_king;
          } else {
            opp_king = black_king;
          }

          if (abs(opp_king.line - line) == abs(opp_king.col - col)) {
            int lstep = (opp_king.line - line) / abs(opp_king.line - line);
            int cstep = (opp_king.col - col) / abs(opp_king.col - col);
            bool dies = true;
            for (int moved = 1; moved < abs(opp_king.col - col); moved++) {
              int l = opp_king.line - lstep * moved;
              int c = opp_king.col - cstep * moved;
              if (l >= 0 && l < 8 && c >= 0 && c < 8)
                dies = dies && (board[l][c] == '.');
            }
            if (dies) goto someone_dies_3;
          }

          if (opp_king.line == line) {
            int step = (opp_king.col - col) / abs(opp_king.col - col);
            bool dies = true;
            for (int moved = 1; moved < abs(opp_king.col - col); moved++) {
              int c = opp_king.col - moved * step;
              if (c >= 0 && c < 8)
                dies = dies && (board[line][c] == '.');
            }
            if (dies) goto someone_dies_3;
          }

          if (opp_king.col == col) {
            int step = (opp_king.line - line) / abs(opp_king.line - line);
            bool dies = true;
            for (int moved = 1; moved < abs(opp_king.line - line); moved++) {
              int l = opp_king.line - moved * step;
              if (l >= 0 && l < 8)
                dies = dies && (board[l][col] == '.');
            }
            if (dies) goto someone_dies_3;
          }

          goto check_knight;

          someone_dies_3:
            if (board[line][col] == 'q') {
              goto white_dies;
            } else {
              goto black_dies;
            }
        }

        check_knight:
        if (board[line][col] == 'n' || board[line][col] == 'N') {

          pos opp_king;
          if (board[line][col] == 'n') {
            opp_king = white_king;
          } else {
            opp_king = black_king;
          }

          if ((abs(opp_king.line - line) == 2) && (abs(opp_king.col - col) == 1)) goto someone_dies_4;
          if ((abs(opp_king.line - line) == 1) && (abs(opp_king.col - col) == 2)) goto someone_dies_4;

          continue;

          someone_dies_4:
            if (board[line][col] == 'n') {
              goto white_dies;
            } else {
              goto black_dies;
            }
        }

      }
    }

    cout << "Game #" << game << ": no king is in check.\n";
    continue;

    white_dies:
    cout << "Game #" << game << ": white king is in check.\n";
    continue;

    black_dies:
    cout << "Game #" << game << ": black king is in check.\n";
    continue;

  }

  return 0;
}