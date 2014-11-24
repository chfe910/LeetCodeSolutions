
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
        unsigned char certifier[10];
        
        // Each row must have the numbers 1-9 occuring just once.
        for (int i = 0; i < board.size(); ++i) {
            memset(certifier, 0, sizeof(unsigned char) * 10);
            for (int j = 0; j < board[0].size(); ++j) {
                char cell = board[i][j];
                if (cell != '.') {
                    cell -= '0';
                    if (certifier[cell]) return false;
                    else certifier[cell] = 1;
                }
            }
        }
        
        // Each column must have the numbers 1-9 occuring just once.
        for (int j = 0; j < board[0].size(); ++j) {
            memset(certifier, 0, sizeof(unsigned char) * 10);
            for (int i = 0; i < board.size(); ++i) {
                char cell = board[i][j];
                if (cell != '.') {
                    cell -= '0';
                    if (certifier[cell]) return false;
                    else certifier[cell] = 1;
                }
            }
        }
        
        // And the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid.
        for (int m = 0; m < board.size(); m += 3) {
            for (int n = 0; n < board[0].size(); n += 3){
                memset(certifier, 0, sizeof(unsigned char) * 10);
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        char cell = board[m + i][n + j];
                        if (cell != '.') {
                            cell -= '0';
                            if (certifier[cell]) return false;
                            else certifier[cell] = 1;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};

class Solution1 {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
        unsigned char rowCertifier[9][9] = {0}, colCertifier[9][9] = {0}, boxCertifier[9][9] = {0};
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                char cell = board[i][j];
                if (cell != '.') {
                    cell -= '1';
                    if (rowCertifier[i][cell]) return false; // Each row must have the numbers 1-9 occuring just once.
                    else rowCertifier[i][cell] = 1;
                    if (colCertifier[cell][j]) return false; // Each column must have the numbers 1-9 occuring just once.
                    else colCertifier[cell][j] = 1;
                    if (boxCertifier[i/3*3 + j/3][cell]) return false; // And the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid.
                    else boxCertifier[i/3*3 + j/3][cell] = 1;
                }
            }
        }
        
        return true;
    }
};
