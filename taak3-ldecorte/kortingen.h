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
    vastekorting(const product &product, const std::string &soort, const std::string &startdate, const std::string &enddate, const float &procent): korting(product, soort, startdate, enddate), procent_(procent){};
    ~vastekorting(){};
    
    virtual float berekenKorting(int aantal){
        product item = getItem();
        double prijs = aantal * item.getPrijs();
        return prijs / 100 * procent_;
    }
    virtual bool geldig(int aantal){
        return true;
    }
    virtual void printKorting(int aantal){
        std::cout << "-" << berekenKorting(aantal) << "\t " << procent_ << "% vaste korting " << " ( einde " << getEndDate() <<  ")\n";
    }
    
    virtual void printInfo(){
        std::cout << procent_ << "% vaste korting " << " ( einde " << getEndDate() <<  ")\n";
    
    }
    virtual float getprocent(){return procent_;}

    virtual int getminimum() = 0;
    virtual int getgratis() = 0;
private:
    float procent_;
};

struct nkopenmgratis : public korting{
    nkopenmgratis(const product &product, const std::string &soort, const std::string &startdate,  const std::string &enddate, const int &kaantal, const int &gaantal, const float &procent):
        korting(product, soort, startdate, enddate),
        kortingsaantal_(kaantal),
        gratisaantal_(gaantal),
        procent_(procent){};
    ~nkopenmgratis(){};

    
    
    virtual float berekenKorting(int aantal){
        int aantalgratis = aantal/(kortingsaantal_+ gratisaantal_);
        if(aantalgratis >= 1){
            product item = getItem();
            double prijs = aantal * item.getPrijs();
            return prijs * aantalgratis;
        }
        return 0;
    }
    virtual bool geldig(int aantal)
    {
        if(aantal >= kortingsaantal_){
            return true;
        }
        return false;
    }
    
    virtual void printKorting(int aantal){
        std::cout << "-" << berekenKorting(aantal ) << "\t " << kortingsaantal_ << "kopen" << gratisaantal_ << "gratis" << " ( einde " << getEndDate() <<  ")\n";
    }
    
    virtual void printInfo(){
        std::cout << kortingsaantal_ << "kopen" << gratisaantal_ << "gratis" << " ( einde " << getEndDate() <<  ")\n"; }
    
    virtual float getprocent(){return procent_;}
    virtual int getminimum(){return kortingsaantal_;}
    virtual int getgratis(){return gratisaantal_;}
private:
    int kortingsaantal_;
    int gratisaantal_;
    float procent_;
};

struct volumekorting : public korting{
    volumekorting(const product &product, const std::string &soort, const std::string &startdate, const std::string &enddate, const int &kaantal, const float &procent):
    korting(product, soort, startdate, enddate),
    kortingsaantal_(kaantal),
    procent_(procent){};
    ~volumekorting(){};
    
    
    virtual float berekenKorting(int aantal){
        if(aantal >= kortingsaantal_){
            product item = getItem();
            double prijs = aantal * item.getPrijs();
            return prijs / 100 * procent_;
        }
        return 0;
    }
    virtual bool geldig(int aantal)
    {
        if(aantal >= kortingsaantal_){
            return true;
        }
        return false;
    }
    
    virtual void printKorting(int aantal){
        std::cout << "-" << berekenKorting(aantal) << "\t " << procent_ << "% korting vannaf " << kortingsaantal_ << " ( einde " << getEndDate() <<  ")\n";   }
    
    virtual void printInfo(){
        std::cout << procent_ << "% korting vannaf " << kortingsaantal_ << " ( einde " << getEndDate() <<  ")\n";   }
    
    virtual float getprocent(){return procent_;}
    virtual int getminimum(){return kortingsaantal_;}
    virtual int getgratis() = 0;
private:
    int kortingsaantal_;
    float procent_;
};





#endif /* defined(__taak3_ldecorte__kortingen__) */
