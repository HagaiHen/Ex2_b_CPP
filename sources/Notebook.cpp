#include <string>
#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>

using namespace ariel;


void Notebook::write(unsigned int page, unsigned int row, unsigned int col, Direction d, std::string const &str) {
    this->last_use[page] = row;
    int const n = 99;
    for (char c: str) {
        if (this->note[page][row][col].ch == '_' && col < n) {
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

std::string Notebook::read(unsigned int page, unsigned int row, unsigned int col, Direction d, unsigned int len) {
    std::string s;
    for (int i = 0; i < len; i++) {
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

void Notebook::erase(unsigned int page, unsigned int row, unsigned int col, Direction d, unsigned int len) {
    this->last_use[page] = row;
    for (int i = 0; i < len; i++) {
        this->note[page][row][col].ch = '~';
        if (d == ariel::Direction::Horizontal) {
            col++;
        } else {
            row++;
        }
    }
}

void Notebook::show(unsigned int page) {
    int const len = 100;
    unsigned int row = this->last_use[page];
    Direction d = ariel::Direction::Horizontal;
    int tmpRow = (int) row;
    if (row > 0) {
        for (int i = tmpRow - 1; i <= row + 1; i++) {
            this->read(page, (unsigned int)i, 0, d, len);
        }
    } else {
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j < len; j++) {
                cout << this->note[page][(unsigned int)j][(unsigned int)i].ch;
            }
            cout << endl;
        }

    }
}




