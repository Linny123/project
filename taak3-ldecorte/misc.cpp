//
//  misc.cpp
//  taak3-ldecorte
//
//  Created by linda de corte on 21-12-14.
//  Copyright (c) 2014 linda de corte. All rights reserved.
//

#include "misc.h"
#include <string.h>
#include <vector>
#include <array>
#include "korting.h"
#include <time.h>
#include "misc.h"


std::string getDate(){
    char tijd[80];
    time_t rawtime;
    std::time( &rawtime );
    struct tm *info;
    info = localtime( &rawtime );
    std::strftime (tijd, 80, "%d/%m/%Y", info);
    
    std::stringstream ss;
    std::string s;
    ss << tijd;
    ss >> s;
    
    return s;
    
}
int * fromStringtoDate( std::string date){
    static int adate[3];
    for (int i=0; i<date.length(); i++)
    {
        if (date[i] == '/')
            adate[i] = ' ';
    }
    std::stringstream ss(date);
    ss >> adate[0]; //day
    ss >> adate[1]; //month
    ss >> adate[2]; //year
    return adate;
}
std::string toStringDate(int date[3]){
    std::string korting;
    korting.append(std::to_string(date[0]));
    korting.append("/");
    korting.append(std::to_string(date[1]));
    korting.append("/");
    korting.append(std::to_string(date[2]));
    
    return korting;
    
}
