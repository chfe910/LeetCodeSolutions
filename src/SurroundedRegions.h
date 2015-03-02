
#include "../MyLeetCode/stdafx.h"


class Solution {
public:
	void solve(vector<vector<char>> &board) {
		int height = board.size();
		if (height == 0) return;
		int width = board[0].size();
		if (width == 0) return;

		for (int i = 0; i < height; ++i) {
			if (board[i][0] == 'O') BFSBoundary(board, i, 0);
			if (board[i][width - 1] == 'O') BFSBoundary(board, i, width - 1);
		}

		for (int j = 1; j < width - 1; ++j) {
			if (board[0][j] == 'O') BFSBoundary(board, 0, j);
			if (board[height - 1][j] == 'O') BFSBoundary(board, height - 1, j);
		}

		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				if (board[i][j] == 'O') board[i][j] = 'X';
				if (board[i][j] == '#') board[i][j] = 'O';
			}
		}
    }

private:
	void BFSBoundary(vector<vector<char>> &board, int h, int w) {
		int height = board.size();
		int width = board[0].size();

		queue<pair<int, int>> q;
		q.push(make_pair(h, w));
		board[h][w] = '#';

		while (!q.empty()) {
			pair<int, int> point = q.front();
			q.pop();

			pair<int, int> neighbors[4] = {	{ point.first + 1, point.second },
											{ point.first - 1, point.second },
											{ point.first, point.second + 1 },
											{ point.first, point.second - 1 } };

			for (auto neig : neighbors) {
				if ((neig.first >= 0 && neig.first < height)
					&& (neig.second >= 0 && neig.second < width)
					&& (board[neig.first][neig.second] == 'O')){
					q.push(make_pair(neig.first, neig.second));
					board[neig.first][neig.second] = '#';
				}
			}
		}
	}
};

class Tester{
public:
	int test() {
		vector<vector<char>> board(1);
		board[0].push_back('O');
		
		Solution sol;
		sol.solve(board);
		return 0;
	}
};