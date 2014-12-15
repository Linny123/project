//
//  verkoopBon.h
//  taak3-ldecorte
//
//  Created by linda de corte on 21-11-14.
//  Copyright (c) 2014 linda de corte. All rights reserved.
//

#ifndef __taak3_ldecorte__verkoopBon__
#define __taak3_ldecorte__verkoopBon__

#include <stdio.h>
#include <map>
#include "Product.h"


class productKorting{
private:
    long barcode_;
    int aantal_;
    double prijs_;
    int korting_;
    
public:
    int getAantal();
    void addAantal(const int &aantal);
    double getPrijs();
    double getKortingProcent();
    std::string getKortingText();
    
    productKorting(const long &barcode, const int &aantal);
    
};

class verkoopBon{
private:
    std::map<long, int> productlijst_;
public:
    void add(const long &barcode, const int &aantal);
    product getproduct(const long &barcode);
    void verwijder(const long &barcode, const int &aantal);
    void printBon();
    verkoopBon();
    
};



#endif /* defined(__taak3_ldecorte__verkoopBon__) */
