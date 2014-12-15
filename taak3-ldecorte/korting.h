//
//  korting.h
//  taak3-ldecorte
//
//  Created by linda de corte on 21-11-14.
//  Copyright (c) 2014 linda de corte. All rights reserved.
//

#ifndef __taak3_ldecorte__korting__
#define __taak3_ldecorte__korting__

#include <string>
#include <fstream>
#include <iomanip>
#include "Product.h"
#include <stdio.h>
#include <vector>
#include <array>



class korting{
private:
    std::string soort_;
    int aantal_;
    int startDate[3];
    int endDate[3];
    product item_;
    int *  fromStringtoDate(std::string date);
    std::string toStringStartDate( int date[3]);
    
    std::string getDate();
    
    
    
public:
    std::string getSoort();
    void addSoort(const std::string &soort);
    std::string getStartDate();
    void addStartDate(const std::string &date);
    std::string getEndDate();
    void addEndDate(const std::string &date);
    bool stillOpen();
    product getItem();
    int getAantal();
    void pluseen();
    product addItem(const product &product);
    
    korting(const product &product, const std::string &soort, const std::string &startdate, const std::string &enddate);
    korting();
    
    
};

#endif /* defined(__taak3_ldecorte__korting__) */
