//
//  data_sql.h
//  ob
//
//  Created by Даниил on 29.03.2021.
//

#pragma once

#include "sqlite.h"
#include "H_lowboy.h"
#include <string>
#include <fstream>

class data_sql {
private:
    lowboy llowboy;
public:
    lowboy read (const char* input_file_name){
        lowboy lowboy;
        
        sqlite3* db = 0;
        sqlite3_stmt* stmt;
        sqlite3_stmt* stmt2;
        char* err = 0;
        
        if (sqlite3_open(input_file_name, &db))
            fprintf(stderr, "tesst", sqlite3_errmsg(db));
        else{
            
                
        }
        return lowboy;
    }
    
    void write(lowboy lowboy, const char* output_file_name);
};
