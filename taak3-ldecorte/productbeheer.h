//
//  productbeheer.h
//  taak3-ldecorte
//
//  Created by linda de corte on 21-12-14.
//  Copyright (c) 2014 linda de corte. All rights reserved.
//

#ifndef __taak3_ldecorte__productbeheer__
#define __taak3_ldecorte__productbeheer__

#include <stdio.h>
#include <iostream>
#include "Productlijst.h"
#include "Product.h"
#include "kortingslijst.h"
#include "extrakorting.h"
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <queue>



void productbeheer(productList productLijst,  kortingslijst kortingslijstje, extrakorting extrakortingen){
    bool run = true;
    bool wijzigingen = false;
    std::string lijn;
    std::string opdracht1;
    std::string opdracht;
    std::string leeg;
    while ( run){
        getline(std::cin, lijn, '\n');
        std::istringstream ifs(lijn);
        ifs>>opdracht1;
        if(opdracht1 == "product"){
            ifs>>opdracht;
        
            if (opdracht == "list"){
                productLijst.printProductlijst();
            }
            else if(opdracht == "add")
            {
                long barcode;
                ifs>>barcode;
                productLijst.voegProductToe(barcode);
                wijzigingen = true;
            }
            else if(opdracht == "remove")
            {
                long barcode;
                ifs>>barcode;
                productLijst.verwijderProduct(barcode);
                wijzigingen = true;
                
            }
            else if(opdracht == "edit")
            {
                long barcode;
                ifs>>barcode;
                productLijst.WijzigProduct(barcode);
                wijzigingen = true;
            }
            else if(opdracht == "stock")
            {
                long barcode;
                std::string aantal;
                ifs>>barcode;
                ifs>>aantal;
                productLijst.stockUpdate(barcode, aantal);
                wijzigingen = true;
            }
            else if(opdracht == "save")
            {
                productLijst.schrijfProductlijstWeg();
                wijzigingen = false;
            }
            else if(opdracht == "quit")
            {
                if(wijzigingen){
                    std::cout << "Er zijn wijzigingen, wilt u opslaan? (j, n) \n";
                    getline(std::cin, lijn, '\n');
                    std::ifstream ifs (lijn);
                    if (lijn != "n"){
                        productLijst.schrijfProductlijstWeg();
                    }
                    
                    }
                    run = false;
                    }
        }
    
        if(opdracht1 == "discount"){
            ifs>>opdracht;
            
            if(opdracht == "ADD"){
                long barcode;
                std::string soort;
                ifs>>barcode;
                ifs>>soort;
                kortingslijstje.addkorting(barcode, soort);
            }
            if(opdracht == "del"){
                long barcode;
                ifs>>barcode;
                kortingslijstje.removekorting(barcode);
            }
            if(opdracht == "list"){
                kortingslijstje.printkortingen();
            }
        }
        if(opdracht1 == "klanten"){
            ifs>>opdracht;
            
            if(opdracht == "ADD"){
                long klantnummer;
                std::string naam;
                ifs>>klantnummer;
                ifs>>naam;
                extrakortingen.addklant(klantnummer, naam);
            }
        }
            
            
            
        }
    }


#endif /* defined(__taak3_ldecorte__productbeheer__) */
