//
//  kortingslijst.h
//  taak3-ldecorte
//
//  Created by linda de corte on 19-12-14.
//  Copyright (c) 2014 linda de corte. All rights reserved.
//

#ifndef __taak3_ldecorte__kortingslijst__
#define __taak3_ldecorte__kortingslijst__

#include <stdio.h>
#include <map>
#include "korting.h"
#include <string.h>
#include <list>
#include <time.h>
#include "Productlijst.h"

typedef std::multimap<long, korting> lkmap;
class kortingslijst{
private:
    lkmap kortingslijst_;
    productList productlijst_;
    std::string locatie_;
    
    
    
public:
    kortingslijst(const productList &productlijst, std::string locatie);
    void addkorting(const long &barcode, const std::string &soort);
    void removekorting(const long &barcode);
    korting findkorting(const long &barcode);
    void printkortingen();
    void schrijfKortingsLijstWeg();
    
    
};

#endif /* defined(__taak3_ldecorte__kortingslijst__) */
