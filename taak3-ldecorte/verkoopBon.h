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
#include "kortingslijst.h"
#include "kortingen.h"
#include "korting.h"

struct bonproduct{
private:
    product item_;
    int aantal_;
public:
    product getItem(){
        return item_;
    }
    void addAantal(int plusaantal){
        aantal_ = aantal_ + plusaantal;
    }
    void printItem(){
        float totaal = aantal_ * item_.getPrijs();
        std::cout << item_.getBarcode() << "\t" << aantal_ << "\t" << item_.getName() << "\t" << totaal << "\t";
    }
};



class verkoopBon{
private:
    std::map<long, product> productlijst_;
    std::map<long, korting> kortingslijst_;
    std::map<long, bonproduct> bon_;
    
public:
    void add(const long &barcode, const int &aantal);
    product getproduct(const long &barcode);
    void verwijder(const long &barcode, const int &aantal);
    void printBon();
    verkoopBon();
    
};



#endif /* defined(__taak3_ldecorte__verkoopBon__) */
