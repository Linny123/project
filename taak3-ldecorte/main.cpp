//
//  main.cpp
//  taak3-ldecorte
//
//  Created by linda de corte on 21-11-14.
//  Copyright (c) 2014 linda de corte. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include "Productlijst.h"
#include "Product.h"
#include "korting.h"
#include "kortingen.h"
#include "kortingslijst.h"
#include "extrakorting.h"
#include "verkoopBon.h"
#include "productbeheer.h"
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <queue>



int main(int argc, const char * argv[]) {
    
    productList productLijst("/users/lindadecorte/Dropbox/VUB/prijslijst.txt");
    kortingslijst kortingslijstje(productLijst, "/users/lindadecorte/Dropbox/VUB/kortingslijst.txt");
    extrakorting extrakortingen;
    
    if(argv[1] == std::string("beheer")){
        productbeheer(productLijst, kortingslijstje, extrakortingen);
    }
    else if(argv[1] == std::string("verkoop")) {
        verkoopinterface(productLijst, kortingslijstje, extrakortingen)
    }

    
    
    
 
    return 0;
}
