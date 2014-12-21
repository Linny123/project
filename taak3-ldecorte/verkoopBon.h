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
#include "extrakorting.h"

struct bonproduct{
private:
    product item_;
    int aantal_;
    long barcode_;
public:
    bonproduct(product item, int aantal):item_(item), aantal_(aantal){}
    product getItem(){
        return item_;
    }
    void addAantal(int plusaantal){
        aantal_ = aantal_ + plusaantal;
    }
    int getAantal(){
    return aantal_;
    }
    long getBarcode(){
        return barcode_;
    }
    void printItem(){
        float totaal = aantal_ * item_.getPrijs();
        std::cout << item_.getBarcode() << "\t" << aantal_ << "\t" << item_.getName() << "\t" << totaal << "\t";
    }
};



class verkoopBon{
private:
    productList productlijst_;
    kortingslijst kortingslijst_;
    std::map<long, bonproduct> bon_;
    extrakorting extrakorting_;
    float prijs_ = 0;
    
public:
    void add(const long &barcode, const int &aantal);
    product getproduct(const long &barcode){
        return bon_[barcode].getItem();
    }
    void verwijder(const long &barcode, const int &aantal);
    void printBon();
    verkoopBon(const productList &productlijst, const kortingslijst & kortingslijst, const extrakorting &extrakort): productlijst_(productlijst), kortingslijst_(kortingslijst), extrakorting_(extrakort){}
    
};



#endif /* defined(__taak3_ldecorte__verkoopBon__) */
