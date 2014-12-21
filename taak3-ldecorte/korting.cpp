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
#include "Productlijst.h"
#include "misc.h"
    

    std::string korting::getSoort(){
    
        return soort_;
    }


std::string korting::toStringDate( int date[3]){
    std::stringstream string;
    string << date[0] << "/" << date[1] << "/" << date[2];
    std::string dates;
    string >> dates;
    return dates;
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

bool korting::inDate(const std::string &startdate, const std::string &enddate){
    int start[3];
    int end[3];
    
    start[0] = fromStringtoDate(startdate)[0];
    start[1] = fromStringtoDate(startdate)[1];
    start[2] = fromStringtoDate(startdate)[2];
    
    
    end[0] = fromStringtoDate(enddate)[0];
    end[1] = fromStringtoDate(enddate)[1];
    end[2] = fromStringtoDate(enddate)[2];
    
    if(((end[2] >= startDate[2]) and (startDate[2] >= start[2])) or
       ((end[2] >= endDate[2]) and (endDate[2] >= start[2])) or
       ((end[2] >= endDate[2]) and (startDate[2] >= start[2])) or
       ((endDate[2] >= end[2]) and (start[2] >= startDate[2]))){
        if(((end[1] >= startDate[1]) and (startDate[1] >= start[1])) or
           ((end[1] >= endDate[1]) and (endDate[1] >= start[1])) or
           ((end[1] >= endDate[1]) and (startDate[1] >= start[1])) or
           ((endDate[1] >= end[1]) and (start[1] >= startDate[1]))){
            if(((end[0] >= startDate[0]) and (startDate[0] >= start[0])) or
               ((end[0] >= endDate[0]) and (endDate[0] >= start[0])) or
               ((end[0] >= endDate[0]) and (startDate[0] >= start[0])) or
               ((endDate[0] >= end[0]) and (start[0] >= startDate[0]))){
                return true;
            }
        }
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


