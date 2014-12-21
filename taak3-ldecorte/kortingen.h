//
//  kortingen.h
//  taak3-ldecorte
//
//  Created by linda de corte on 19-12-14.
//  Copyright (c) 2014 linda de corte. All rights reserved.
//

#ifndef __taak3_ldecorte__kortingen__
#define __taak3_ldecorte__kortingen__

#include <stdio.h>
#include "korting.h"

struct vastekorting : public korting{
    vastekorting(const product &product, const std::string &soort, const std::string &startdate, const std::string &enddate, const int &aantal, const float &procent): korting(product, soort, startdate, enddate, aantal), procent_(procent){};
    
    float berekenKorting(){
        product item = getItem();
        double prijs = getAantal() * item.getPrijs();
        return prijs / 100 * procent_;
    }
    bool geldig(){
        return true;
    }
    void printKorting(){
        std::cout << "-" << berekenKorting() << "\t " << procent_ << "% vaste korting " << " ( einde " << getEndDate() <<  ")\n";
    }
    
    void printInfo(){
        std::cout << procent_ << "% vaste korting " << " ( einde " << getEndDate() <<  ")\n";
    
    }
private:
    float procent_;
};

struct nkopenmgratis : public korting{
    nkopenmgratis(const product &product, const std::string &soort, const std::string &startdate,  const std::string &enddate, const int &aantal, const int &kaantal, const int &gaantal, const float &procent):
        korting(product, soort, startdate, enddate, aantal),
        kortingsaantal_(kaantal),
        gratisaantal_(gaantal),
        procent_(procent){};
    

    
    
    float berekenKorting(){
        int aantalgratis = getAantal()/(kortingsaantal_+ gratisaantal_);
        if(aantalgratis >= 1){
            product item = getItem();
            double prijs = getAantal() * item.getPrijs();
            return prijs * aantalgratis;
        }
        return 0;
    }
    bool geldig()
    {
        if(getAantal() >= kortingsaantal_){
            return true;
        }
        return false;
    }
    
    void printKorting(){
        std::cout << "-" << berekenKorting() << "\t " << kortingsaantal_ << "kopen" << gratisaantal_ << "gratis" << " ( einde " << getEndDate() <<  ")\n";
    }
    
    void printInfo(){
        std::cout << kortingsaantal_ << "kopen" << gratisaantal_ << "gratis" << " ( einde " << getEndDate() <<  ")\n"; }
    
private:
    int kortingsaantal_;
    int gratisaantal_;
    float procent_;
};

struct volumekorting : public korting{
    volumekorting(const product &product, const std::string &soort, const std::string &startdate, const std::string &enddate, const int &aantal, const int &kaantal, const float &procent):
    korting(product, soort, startdate, enddate, aantal),
    kortingsaantal_(kaantal),
    procent_(procent){};
    
    
    
    float berekenKorting(){
        if(getAantal() >= kortingsaantal_){
            product item = getItem();
            double prijs = getAantal() * item.getPrijs();
            return prijs / 100 * procent_;
        }
        return 0;
    }
    bool geldig()
    {
        if(getAantal() >= kortingsaantal_){
            return true;
        }
        return false;
    }
    
    void printKorting(){
        std::cout << "-" << berekenKorting() << "\t " << procent_ << "% korting vannaf " << kortingsaantal_ << " ( einde " << getEndDate() <<  ")\n";   }
    
    void printInfo(){
        std::cout << procent_ << "% korting vannaf " << kortingsaantal_ << " ( einde " << getEndDate() <<  ")\n";   }
private:
    int kortingsaantal_;
    float procent_;
};





#endif /* defined(__taak3_ldecorte__kortingen__) */
