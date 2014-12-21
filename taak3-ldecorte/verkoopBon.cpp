//
//  verkoopBon.cpp
//  taak3-ldecorte
//
//  Created by linda de corte on 21-11-14.
//  Copyright (c) 2014 linda de corte. All rights reserved.
//

#include "verkoopBon.h"
#include "Productlijst.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <locale>
#include <sstream>
#include <stdlib.h>
#include <map>
#include "Product.h"


void verkoopBon::add(const long &barcode, const int &aantal){
    if (bon_.count( barcode ) > 0){
        bon_[barcode].addAantal(aantal);
    }
    else {
        bonproduct item(productlijst_.neemProduct(barcode), aantal);
        bon_[barcode] = item;
    }
}

void verkoopBon::verwijder(const long &barcode, const int &aantal){
    if(bon_.count(barcode) > 0 ){
        bon_.erase (barcode);
    }
        else{
            std::cout << "Er is nog geen product aangeslagen met de barcode: " << barcode << "\n";
        }
}
void verkoopBon::printBon(){
    
    // print first line
    std::cout << "Streepjescode \t Aantal \t Naam \t \t \t Totaal \t Korting \n";
    float totalekorting = 0;
    std::map<long, bonproduct> ::iterator it;
    
    // show content:
    for (std::map<long, bonproduct>::iterator it=bon_.begin(); it!=bon_.end(); ++it){
        bonproduct leeg = it->second;
        leeg.printItem();
        kortingslijst_.findkorting(leeg.getBarcode()).printKorting(leeg.getAantal());
        float korting = kortingslijst_.findkorting(leeg.getBarcode()).berekenKorting(leeg.getAantal());
        totalekorting = totalekorting + korting;
        prijs_ = prijs_ + leeg.getAantal() * leeg.getItem().getPrijs() - korting;
        
    }
    std::cout << "Subtotaal: \t" << prijs_ << "\n";
    if(extrakorting_.isgeldig()){
        std::cout << "Extra korting: \t" << totalekorting << "\n";
        std::cout << "Te betalen: \t" << prijs_ - totalekorting << "\n";
    }
    
    

    
}