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
            unordered_map<unsigned int, unsigned int> last_use;
            unordered_map<unsigned int, unordered_map<unsigned int, unordered_map<unsigned int, space>>> note;
        
        public:
            void write(unsigned int page, unsigned int row, unsigned int col, Direction d, std::string const &str);
            std::string read (unsigned int page, unsigned int row, unsigned int col, Direction d, unsigned int len);
            void erase(unsigned int page, unsigned int row, unsigned int col, Direction d, unsigned int len);
            void show(unsigned int page);

	};

}