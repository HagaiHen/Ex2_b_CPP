#include <iostream>
#include "sources/Notebook.hpp"
#include "sources/Direction.hpp"
#include "sources/Notebook.cpp"
#include <string>
using namespace ariel;

int main() {
    Notebook n;
    Direction d = Direction::Horizontal;
    n.write(0, 0, 0, d, "hey");
    n.read(0,0,0, d, 5);
    cout << endl;
    n.erase(0,0,0,d,3);
    n.read(0,0,0, d, 5);
    n.read(0,1,0, d, 5);
    n.read(0,2,0, d, 5);
    n.read(0,3,0, d, 5);
    cout << endl;
    n.write(0, 2, 0,d, "hagai");
    n.read(0,0,0, d, 5);
    n.read(0,1,0, d, 5);
    n.read(0,2,0, d, 5);
    n.read(0,3,0, d, 5);
    cout << endl;
    n.show(0);
    cout << endl;
    n.erase(0,3,48, d, 4);
    n.show(0);
    return 0;
}