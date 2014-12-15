//
//  beheer.cpp
//  taak3-ldecorte
//
//  Created by linda de corte on 21-11-14.
//  Copyright (c) 2014 linda de corte. All rights reserved.
//

#include "beheer.h"
#include <iostream>
#include "Productlijst.h"
#include "Product.h"
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <queue>

void beheer(productList productLijst){
    
    bool run = true;
    bool wijzigingen = false;
    std::string lijn;
    std::string opdracht;
    std::string leeg;
    while ( run){
        getline(std::cin, lijn, '\n');
        std::istringstream ifs(lijn);
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

}