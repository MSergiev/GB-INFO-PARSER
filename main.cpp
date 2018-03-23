#include <iostream>
#include "PARSER.h"

const char* filename = "rom.gb";

int main( int argc, const char* argv[] ) {
    
    if( argc < 2 ) {
        PARSER::parse( filename );
    }
    else {
        PARSER::parse( argv[1] );
    }
	

	return 0;
}
