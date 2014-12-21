//
//  kortingslijst.cpp
//  taak3-ldecorte
//
//  Created by linda de corte on 19-12-14.
//  Copyright (c) 2014 linda de corte. All rights reserved.
//

#include "kortingslijst.h"
#include <time.h>
#include "misc.h"
#include "kortingen.h"
#include "Product.h"



kortingslijst::kortingslijst(const productList &productlijst, std::string locatie) :
    productlijst_(productlijst), locatie_(locatie) {
        long barcode;
        std::string startdatum;
        std::string einddatum;
        std::string soort;
        
        std::string lijn;
        
        std::ifstream ifs (locatie);   //zet invoer file op stream
        while (true){
            
            if (ifs.eof()){
                break;}
            ifs>>barcode;
            ifs>>startdatum;
            ifs>>einddatum;
            ifs>>soort;
            product prod = productlijst_.neemProduct(barcode);
            
            if (soort == "VAST"){
                float procent;
                vastekorting kort(prod, soort, startdatum, einddatum, procent);
                kortingslijst_.insert( std::pair<long, korting>(barcode, kort));
            }
            if (soort == "EXTRA"){
                float procent;
                int minimum;
                int gratis;
                nkopenmgratis kort(prod, soort, startdatum, einddatum, minimum, gratis, procent);
                kortingslijst_.insert( std::pair<long, korting>(barcode, kort));
            }
            if (soort == "VOLUME"){
                float procent;
                int minimum;
                volumekorting kort(prod, soort, startdatum, einddatum, minimum, procent);
                kortingslijst_.insert( std::pair<long, korting>(barcode, kort));

            }
        }
    
    }

void kortingslijst::addkorting(const long &barcode, const std::string &soort){
    if(productlijst_.bestaatProduct(barcode)){
        std::string today = getDate();
        std::cout << "startdatum? [" << today[0] << "/" << today[1] << "/" << today[2] << "]";
        std::string startdatum = "leeg";
        std::string invoerlijn;
        getline(std::cin, invoerlijn, '\n');
        std::istringstream iss(invoerlijn);
        iss>>startdatum;
        std::cout << "einddatum? " ;
        std::string einddatum = "leeg";
        getline(std::cin, invoerlijn, '\n');
        iss>>einddatum;
        
        for(lkmap::iterator it = kortingslijst_.lower_bound(barcode);
            it !=kortingslijst_.upper_bound(barcode); it++){
            if(it->second.inDate(startdatum, einddatum)){
                std::cout << "Korting niet toegevoegd: overlapt met eerdere korting. \n";
                return;
            }
        }
        
        float procent = 0;
        int minimum = 0;
        int gratis = 0;
        
        if(soort == "VAST" ){
            std::cout << "Hoeveel percent korting? " ;
            getline(std::cin, invoerlijn, '\n');
            iss>>procent;
        }
        else if(soort == "EXTRA" ){
            std::cout << "Minimum aantal?" ;
            getline(std::cin, invoerlijn, '\n');
            iss>>minimum;
            std::cout << "Gratis aantal?" ;
            getline(std::cin, invoerlijn, '\n');
            iss>>gratis;
            std::cout << "Hoeveel percent korting? " ;
            getline(std::cin, invoerlijn, '\n');
            iss>>procent;
        }
        else if(soort== "VOLUME"){
            std::cout << "Minimum aantal?" ;
            getline(std::cin, invoerlijn, '\n');
            iss>>minimum;
            std::cout << "Hoeveel percent korting? " ;
            getline(std::cin, invoerlijn, '\n');
            iss>>procent;

        }
        else{
            std::cout << "Kon korting niet toevoegen, type onbekend! \n";
            return;
        }
        
        
        product prod = productlijst_.neemProduct(barcode);
        if(soort =="VAST"){
            vastekorting kort(prod, soort, startdatum, einddatum, procent);
            kortingslijst_.insert( std::pair<long, korting>(barcode, kort));
            
        }
        if (soort == "EXTRA"){
            nkopenmgratis kort(prod, soort, startdatum, einddatum, minimum, gratis, procent);
            kortingslijst_.insert( std::pair<long, korting>(barcode, kort));
        }
        
        if (soort == "VOLUME"){
            volumekorting kort(prod, soort, startdatum, einddatum, minimum, procent);
            kortingslijst_.insert( std::pair<long, korting>(barcode, kort));
        }
     
    std::cout << "korting voor artikel" << barcode << " (" << prod.getName() << ") toegevoegd. \n";
    }
    else{
        std::cout << "product met barcode " << barcode <<" bestaat niet \n";
    }
}


void kortingslijst::removekorting(const long &barcode){
    for(lkmap::iterator it = kortingslijst_.lower_bound(barcode);
    it !=kortingslijst_.upper_bound(barcode); it++){
        if(it->second.stillOpen()){
            kortingslijst_.erase (it);
        }
    }
}

korting kortingslijst::findkorting(const long &barcode){
    korting item;
    for(lkmap::iterator it = kortingslijst_.lower_bound(barcode);
       it !=kortingslijst_.upper_bound(barcode); it++){
        if(it->second.stillOpen()){
            return it->second;
        }
    }
    std::cout << "kortingsitem, die nu actief is met barcode " << barcode << " niet gevonden!";
    return item;
}
void kortingslijst::printkortingen(){
    lkmap::iterator it;
    
    // show content:
    for (lkmap::iterator it=kortingslijst_.begin(); it!= kortingslijst_.end(); ++it){
        korting leeg = it->second;
        product empt = leeg.getItem();
        empt.printnaam();
        leeg.printInfo();
    }
    
}

void kortingslijst::schrijfKortingsLijstWeg(){
    
    std::ofstream myfile;
    myfile.open (locatie_);
    
    
    std::map<long, product> ::iterator it;
    
    // show content:
    for (lkmap::iterator it=kortingslijst_.begin(); it!=kortingslijst_.end(); ++it){
        korting leeg = it->second;
        long barcode = leeg.getItem().getBarcode;
        
        std::string startdatum = leeg.getStartDate;
        std::string einddatum = leeg.getEndDate;
        std::string soort = leeg.getsoort;
        myfile << barcode << "\t" << startdatum << "\t" << einddatum << "\t" << soort << "\t";
        if (soort == "VAST"){
            float procent = leeg.getprocent;
            myfile << procent << "\n";
        }
        if (soort == "EXTRA"){
            float procent = leeg.getprocent;
            int minimum = leeg.getminimum;
            int gratis = leeg.getgratis;
            myfile << procent << "\t" << minimum << "\t" << gratis << "\n";
        }
        if (soort == "VOLUME"){
            float procent = leeg.getprocent;
            int minimum = leeg.getminimum;
            myfile << procent << "\t" << minimum << "\n";
        }
    }
    
    
    
    myfile.close();
}

    


