//
//  vastkorting.h
//  taak3-ldecorte
//
//  Created by linda de corte on 05-12-14.
//  Copyright (c) 2014 linda de corte. All rights reserved.
//

#ifndef __taak3_ldecorte__vastkorting__
#define __taak3_ldecorte__vastkorting__

#include <stdio.h>
#include "korting.h"
class korting;

//class vastekorting{
//private:
//    korting korting_;
//    int procent_;
//public:
//    void pluseen();
//    float berekenKorting();
//    void printKorting();
//    bool stillOpen();
//    void addKorting(const product &product, const std::string &soort, const std::string &startdate, const std::string &enddate, const float &procent);
//    std::string getstartDate(); //HIER WAS IK MEE BEZIG!!
//    std::string getEndDate();
//    
//    
//    vastekorting(const product &product, const std::string &soort, const std::string &startdate, const std::string &enddate, const float &procent);
//    
//    
//};
struct vastekorting : public korting{
    vastekorting(const product &product, const std::string &soort, const std::string &startdate, const std::string &enddate, const float &procent): korting(product, soort, startdate, enddate), procent_(procent){};
    int procent_;
    float berekenKorting(){
        product item = getItem();
        double prijs = getAantal() * item.getPrijs();
        return prijs / 100 * procent_;
    }
    void printKorting(){
        std::cout << "-" << berekenKorting() << "\t " << procent_ << "% vaste korting \n";
    }
    
    
    
};

#endif /* defined(__taak3_ldecorte__vastkorting__) */
