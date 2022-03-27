#pragma once
#include <string>
#include "Direction.hpp"
#include <unordered_map>

using namespace std;

struct space {
    char ch = '_';
};

namespace ariel {
    
    class Notebook {
		
        private:
            unordered_map< int,  int> last_use;
            unordered_map< int, unordered_map< int, unordered_map< int, space>>> note;
        
        public:
            void write( int page,  int row,  int col, Direction d, std::string const &str);
            std::string read ( int page,  int row,  int col, Direction d,  int len);
            void erase( int page,  int row,  int col, Direction d,  int len);
            void show( int page);
            
            //destructor
	    ~Notebook() {}

	};

}
