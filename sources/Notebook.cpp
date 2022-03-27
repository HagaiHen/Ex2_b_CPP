#include <string>
#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>

using namespace ariel;


void Notebook::write( int page,  int row,  int col, Direction d, std::string const &str) {
    this->last_use[page] = row;
    int const n = 99;
    int const sm = 32;
    int const bg = 126;
    int const ZERO = 0;
    for (char c: str) {
        if (this->note[page][row][col].ch == '_' && col <= n && c != '\n' and c != '~' and c >= sm and c <= bg and page>=ZERO and row>=ZERO and col>=ZERO) {
            this->note[page][row][col].ch = c;
            if (d == ariel::Direction::Horizontal) {
                col++;
            } else {
                row++;
            }
        } else {
            throw "Error in writing";
        }
    }
}

std::string Notebook::read( int page,  int row,  int col, Direction d,  int len) {
    std::string s;
    int const n = 99;
    int const ZERO = 0;
    if (len <= ZERO) {
    	throw "Error in reading";
    }
    for (int i = 0; i < len; i++) {
    	if (col > n or page<ZERO or row<ZERO or col<ZERO) {
           throw "Error in reading";
    	}
        s.append(1, this->note[page][row][col].ch);
        if (d == ariel::Direction::Horizontal) {
            col++;
        } else {
            row++;
        }
    }
    cout << s << endl;
    return s;
}

void Notebook::erase( int page,  int row,  int col, Direction d,  int len) {
    this->last_use[page] = row;
    int const n = 99;
    int const ZERO = 0;
    if (len <= ZERO) {
    	throw "Error in reading";
    }
    for (int i = 0; i < len; i++) {
    	if (col > n or page<ZERO or row<ZERO or col<ZERO) {
           throw "Error in earsing";
    	}
        this->note[page][row][col].ch = '~';
        if (d == ariel::Direction::Horizontal) {
            col++;
        } else {
            row++;
        }
    }
}

void Notebook::show( int page) {
    int const len = 100;
    int const ZERO = 0;
    if (page < ZERO) {
    	throw "Error in show";
    }
     int row = this->last_use[page];
    Direction d = ariel::Direction::Horizontal;
    int tmpRow = row;
    if (row > 0) {
        for (int i = tmpRow - 1; i <= row + 1; i++) {
            this->read(page, i, 0, d, len);
        }
    } else {
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j < len; j++) {
                cout << this->note[page][j][i].ch;
            }
            cout << endl;
        }

    }
}




