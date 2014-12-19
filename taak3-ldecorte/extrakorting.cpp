//
//  extrakorting.cpp
//  taak3-ldecorte
//
//  Created by linda de corte on 19-12-14.
//  Copyright (c) 2014 linda de corte. All rights reserved.
//

#include "extrakorting.h"
#include <string>
#include <iostream>

extrakorting::extrakorting(){};
extrakorting::extrakorting(float korting): procent_(korting){};

float extrakorting::extrakortingtotaal(float totaalprijs){
    return totaalprijs/100*procent_;
}
bool extrakorting::isklant(long klantennummer){
    if (klantenlijst_.count(klantennummer) > 0){  // als count groter is als 0 dan bestaat het element
        return true;
    }
    return false;
}
void extrakorting::addklant(long klantennummer, std::string naam){
    if(isklant(klantennummer)){
        std::cout << klantennummer << " - " << klantenlijst_[klantennummer] << "bestaat al \n";
    }
    else{
        klantenlijst_[klantennummer] = naam;
    }
}
void extrakorting::addklant(long klantennummer){
    if(isklant(klantennummer)){
        std::cout << klantennummer << " - " << klantenlijst_[klantennummer] << "bestaat al \n";
    }
    else{
        klantenlijst_[klantennummer] = "no name";
    }

}
std::string extrakorting::klantnaam(long klantnummer){
    
    return klantenlijst_[klantnummer];
    
}