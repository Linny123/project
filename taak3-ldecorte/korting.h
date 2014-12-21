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
#include "misc.h"



struct korting{
private:
    std::string soort_;
    int aantal_;
    int startDate[3];
    int endDate[3];
    product item_;
    std::string toStringDate( int date[3]);

    
    
    
public:
    std::string getSoort();
    void addSoort(const std::string &soort);
    std::string getStartDate();
    void addStartDate(const std::string &date);
    std::string getEndDate();
    void addEndDate(const std::string &date);
    bool stillOpen();
    bool inDate(const std::string &startdate, const std::string &enddate);
    product getItem();
    int getAantal();
    void pluseen();
    product addItem(const product &product);
    korting(const product &product, const std::string &soort, const std::string &startdate, const std::string &enddate);
    virtual ~korting(){}
    virtual float berekenKorting() = 0;
    virtual void printInfo() = 0;
    virtual bool geldig() = 0;
    
    
};

#endif /* defined(__taak3_ldecorte__korting__) */
