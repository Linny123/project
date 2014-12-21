//
//  kortingslijst.h
//  taak3-ldecorte
//
//  Created by linda de corte on 19-12-14.
//  Copyright (c) 2014 linda de corte. All rights reserved.
//

#ifndef __taak3_ldecorte__kortingslijst__
#define __taak3_ldecorte__kortingslijst__

#include <stdio.h>
#include <map>
#include "korting.h"
#include <string.h>

class kortingslijst{
private:
    std::multimap<long, korting> kortingslijst_;
    
    
public:
    kortingslijst();
    bool vergelijkkortingen(std::string date, long barcode);
    void addkorting(long barcode, std::string soort);
    void removekorting(long barcode);
    korting findkorting(long barcode);
    void printkortingen();
    
    
};

#endif /* defined(__taak3_ldecorte__kortingslijst__) */
