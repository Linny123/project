//
//  extrakorting.h
//  taak3-ldecorte
//
//  Created by linda de corte on 19-12-14.
//  Copyright (c) 2014 linda de corte. All rights reserved.
//

#ifndef __taak3_ldecorte__extrakorting__
#define __taak3_ldecorte__extrakorting__

#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <map>

class extrakorting{
private:
    float procent_;
    std::map<long, std::string> klantenlijst_;
    
public:
    extrakorting();
    extrakorting(float korting);
    float extrakortingtotaal(float totaalprijs);
    bool isklant(long klantennummer);
    void addklant(long klantennummer, std::string naam);
    void addklant(long klantnummer);
    std::string klantnaam(long klantnummer);
};

#endif /* defined(__taak3_ldecorte__extrakorting__) */
