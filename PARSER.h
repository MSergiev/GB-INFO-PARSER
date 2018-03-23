#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <cstring>
#include <fstream>
#include "ROM_STRUCTURE.h"


class PARSER {
	
public:

	static inline void parse( const char* filename ) {
		
		std::ifstream file( filename, std::ios::binary );
		if( !file ) {
			std::cerr << "ERROR: " << filename << " does not exist!" << std::endl;
			return;
		}

		ParseHeader( file );
	}

	
private:

    
	static inline void ParseHeader( std::ifstream& file ) {
        
        std::cout << "HEADER:" << std::endl;
        ParseTitle( file );
        ParseCGB( file );
        ParseLIC( file );
        ParseSGB( file );
        ParseCART( file );
        ParseROMSIZE( file );
        ParseRAMSIZE( file );
        ParseDEST( file );
        ParseOLIC( file );
        ParseVNUM( file );
        ParseHCHECK( file );
        ParseGCHECK( file );
        ParseLogo( file );
        
    }


private:    // Components
    
    
	static inline void ParseLogo( std::ifstream& file ) {
        
        std::string attr = "LOGO";
        PrintAttr( attr );
        char arr[ GetSize(attr) ];
        ReadData( file, arr, attr );
        std::cout << std::endl;
        PrintLogo( arr );
        
    }

	static inline void ParseTitle( std::ifstream& file ) {
        
        std::string attr = "TITLE";
        PrintAttr( attr );
        char arr[ GetSize(attr) ];
        ReadData( file, arr, attr );
        std::cout << arr << std::endl;
        
    }

	static inline void ParseCGB( std::ifstream& file ) {
        
        std::string attr = "CGB";
        PrintAttr( attr );
        char arr[ GetSize(attr) ];
        ReadData( file, arr, attr );
        std::cout << CGB.at( arr[0] ) << std::endl;
        
    }
    
	static inline void ParseLIC( std::ifstream& file ) {
        
        std::string attr = "LIC";
        PrintAttr( attr );
        char arr[ GetSize(attr) ];
        ReadData( file, arr, attr );
        char val = (arr[0] - '0')*10 + (arr[1] - '0');
        
        if( LIC.find(val) == LIC.end() ) 
            std::cout << "NA" << std::endl;
        else 
            std::cout << LIC.at( val ) << std::endl;
        
    }
    
	static inline void ParseSGB( std::ifstream& file ) {
        
        std::string attr = "SGB";
        PrintAttr( attr );
        char arr[ GetSize(attr) ];
        ReadData( file, arr, attr );
        PrintBool( arr );
        
    }
    
    static inline void ParseCART( std::ifstream& file ) {
        
        std::string attr = "CART";
        PrintAttr( attr );
        char arr[ GetSize(attr) ];
        ReadData( file, arr, attr );
        std::cout << CART.at(arr[0]) << std::endl;
        
    }
    
    static inline void ParseROMSIZE( std::ifstream& file ) {
        
        std::string attr = "ROMSIZE";
        PrintAttr( attr );
        char arr[ GetSize(attr) ];
        ReadData( file, arr, attr );
        std::cout << ROMSIZE.at(arr[0]) << std::endl;
        
    }
    
    static inline void ParseRAMSIZE( std::ifstream& file ) {
        
        std::string attr = "RAMSIZE";
        PrintAttr( attr );
        char arr[ GetSize(attr) ];
        ReadData( file, arr, attr );
        std::cout << RAMSIZE.at(arr[0]) << std::endl;
        
    }
    
    static inline void ParseDEST( std::ifstream& file ) {
        
        std::string attr = "DEST";
        PrintAttr( attr );
        char arr[ GetSize(attr) ];
        ReadData( file, arr, attr );
        std::cout << DEST.at(arr[0]) << std::endl;
        
    }
    
    static inline void ParseOLIC( std::ifstream& file ) {
        
        std::string attr = "OLIC";
        PrintAttr( attr );
        char arr[ GetSize(attr) ];
        ReadData( file, arr, attr );
        std::cout << OLIC.at(arr[0]) << std::endl;
        
    }    
    
    static inline void ParseVNUM( std::ifstream& file ) {
        
        std::string attr = "VNUM";
        PrintAttr( attr );
        char arr[ GetSize(attr) ];
        ReadData( file, arr, attr );
        std::cout << +arr[0] << std::endl;
        
    }    
    
    static inline void ParseHCHECK( std::ifstream& file ) {
        
        std::string attr = "HCHECK";
        PrintAttr( attr );
        char arr[ GetSize(attr) ];
        ReadData( file, arr, attr );
        
        char sum = 0;
        for( unsigned i = 0x134; i <= 0x14C; ++i ) {
            char val;
            file.seekg( i );
            file.read( &val, 1 );
            sum -= val + 1;
        }
        PrintCheck( sum == arr[0] );
        
    }    
    
    static inline void ParseGCHECK( std::ifstream& file ) {
        
        std::string attr = "GCHECK";
        PrintAttr( attr );
        char arr[ GetSize(attr) ];
        ReadData( file, arr, attr );
        short* val = (short*)(arr);
        
        short sum = 0;
        unsigned addr = 0;
        while(1) {
            char val;
            file.seekg(addr);
            file.get( val );
            if( file.eof() ) {
                file.clear();
                break;
            }
            if( addr != HEADER.at("HCHECK").first and 
                addr != HEADER.at("GCHECK").first ) 
                sum += val;
            addr++;
        }
        
        PrintCheck( *val == sum );
        
    }
    
    
private:    // Helper methods
    
    
    static inline unsigned GetAddr( std::string attr ) {
        return HEADER.at(attr).first;
    }

    static inline unsigned GetSize( std::string attr ) {
        return HEADER.at(attr).second;
    }

	static inline void PrintQuad( char in, bool part ) {
        
		for( char k = 3; k >= 0; --k ) {
			std::cout << ( (( in >> (k + 4*!part) )&1) ? '=' : ' ' );
		}
		
	}
	
	static inline void ReadData( std::ifstream& file, char* arr, std::string attr ) {
        file.seekg( GetAddr(attr) );
        file.read( arr, GetSize(attr) );
    }

    
private:    // Print methods
    
    
	static inline void PrintAttr( std::string attr ) {
        
        std::cout << "- " << attr << ": ";
        //std::cout << "(0x" << std::hex << GetAddr(attr);
        //std::cout << ", " << std::dec << GetSize(attr) << "): ";
        
    }
    
    static inline void PrintLogo( char* arr ) {
        
        for( unsigned i = 0; i < 2; ++i ) {
            for( unsigned j = 0; j < 4; ++j ) {
                for( unsigned k = 0; k < 12; ++k ) {
                    PrintQuad( arr[k*2 + j/2 + 24*i], j%2 );
                }
                std::cout << std::endl;
            }
        }
        
    }
    
    static inline void PrintBool( char* arr ) {
        
        std::cout << (arr[0] ? "TRUE" : "FALSE") << std::endl;
        
    }    
    
    static inline void PrintCheck( bool val ) {
        
        std::cout << (val ? "PASS" : "FAIL") << std::endl;
        
    }
    
};


#endif
