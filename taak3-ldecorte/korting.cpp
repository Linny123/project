//
//  korting.cpp
//  taak3-ldecorte
//
//  Created by linda de corte on 21-11-14.
//  Copyright (c) 2014 linda de corte. All rights reserved.
//

#include <string>
#include <fstream>
#include <iomanip>
#include "Product.h"
#include <stdio.h>
#include <vector>
#include <array>
#include "korting.h"
#include <time.h>
#include <sstream>

    std::string korting::getDate(){
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
     int * korting::fromStringtoDate( std::string date){
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


    std::string korting::getSoort(){
    
        return soort_;
    }
    void korting::addSoort(const std::string &soort){
        soort_ = soort;
    }
    std::string korting::getStartDate(){
        return toStringDate(startDate);
    }
    void korting::addStartDate(const std::string &date){
        startDate[0] = fromStringtoDate(date)[0];
        startDate[1] = fromStringtoDate(date)[1];
        startDate[2] = fromStringtoDate(date)[2];
    }
    std::string korting::getEndDate(){
        return toStringDate(endDate);
    }
    void korting::addEndDate(const std::string &date){
        endDate[0] = fromStringtoDate(date)[0];
        endDate[1] = fromStringtoDate(date)[1];
        endDate[2] = fromStringtoDate(date)[2];
    }
    bool korting::stillOpen(){
        std::string todays = getDate();
        int today[3];
        
        today[0] = fromStringtoDate(todays)[0];
        today[1] = fromStringtoDate(todays)[1];
        today[2] = fromStringtoDate(todays)[2];
        
        if(( endDate[2] >= today[2]) + (today[2] >= startDate[2])){
            if((endDate[1] >= today[1]) + (today[1] >= startDate[1])){
                if((endDate[0] >= today[0]) + (today[0] >= startDate[0]))
                    return true; }
        }
        return false;
    }

    


int korting::getAantal(){
    return aantal_;
}
void korting::pluseen(){
    aantal_ ++;
}
   

    product korting::getItem(){
        return item_;
        
    }
    product korting::addItem(const product &product){
        item_ = product;
        
        return item_;
    }




korting::korting(const product &product, const std::string &soort, const std::string &startdate, const std::string &enddate):
        soort_(soort), item_(product){
        addStartDate(startdate);
        addEndDate(enddate);
    }
    korting::korting(){}

