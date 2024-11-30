#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, int num, int rm, int cm,
             vector<vector<int>> &gm) {
  if ((rm & (1 << num)) > 0) {
    return false;
  }

  if ((cm & (1 << num)) > 0) {
    return false;
  }

  if ((gm[row][col] & (1 << num)) > 0) {
    return false;
  }

  return true;
}

bool helper(vector<vector<char>> &board, vector<int> &rm, vector<int> &cm,
            vector<vector<int>> &gm) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == '.') {
        for (int k = '1'; k <= '9'; k++) {
          if (isValid(i / 3, j / 3, k - '0', rm[i], cm[j], gm)) {
            board[i][j] = k;
            rm[i] |= (1 << (k - '0'));
            cm[j] |= (1 << (k - '0'));
            gm[i / 3][j / 3] |= (1 << (k - '0'));

            if (helper(board, rm, cm, gm)) {
              return true;
            } else {
              board[i][j] = '.';
              rm[i] &= ~(1 << (k - '0'));
              cm[j] &= ~(1 << (k - '0'));
              gm[i / 3][j / 3] &= ~(1 << (k - '0'));
            }
          }
        }
        return false;
      }
    }
  }

  return true;
}

void solveSudoku(vector<vector<char>> &board) {
  vector<int> rm(9, 0), cm(9, 0);
  vector<vector<int>> gm(3, vector<int>(3, 0));

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] != '.') {
        int num = board[i][j] - '0';
        rm[i] |= (1 << num);
        cm[j] |= (1 << num);
        gm[i / 3][j / 3] |= (1 << num);
      }
    }
  }

  helper(board, rm, cm, gm);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}