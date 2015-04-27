//
//  ARC.cpp
//  3
//
//  Created by Gregory Moon on 4/21/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#include "ARC.h"

ARC::ARC(int cacheSize){
    p = 0;
    numHits = 0;
    numRequests = 0;
    numMisses = 0;
    hitRatio = 0;
    this->cacheSize = cacheSize;
    
    t1 = new LRU(cacheSize);
    t2= new LRU(cacheSize);

    b1 = new LRU(cacheSize);
    b2 = new LRU(cacheSize);

}

ARC::~ARC(){
    
}

void ARC::add(int page){
    numRequests++;

    if(checkCaseOne(page))
        return;
    
    if(checkCaseTwo(page))
        return;
    
    if(checkCaseThree(page))
        return;
    
    if(checkCaseFour(page))
        return;
    
    printf("There is a problem!\n");
}

bool ARC::checkCaseOne(int page){
    bool retVal = false;
    if(t1->contains(page)){
        t2->add(page);
        t1->removePage(page);
        retVal = true;
        numHits++;
    }
    else if(t2->contains(page)){
        t2->moveToBack(page);
        retVal = true;
        numHits++;
    }

    return retVal;
}

bool ARC::checkCaseTwo(int page){
    bool retVal = false;
    
    if(b1->contains(page)){
        adjust(page, MIN);
        replace(page);
        t2->add(page);
        b1->removePage(page);
        retVal = true;
        numMisses++;
    }
    
    return retVal;
}

bool ARC::checkCaseThree(int page){
    bool retVal = false;
    
    if(b2->contains(page)){
        adjust(page, MAX);
        replace(page);
        t2->add(page);
        b2->removePage(page);
        retVal = true;
        numMisses++;
    }
    
    return retVal;
}

bool ARC::checkCaseFour(int page) {    
    if(t1->getSize() + b1->getSize() == cacheSize){
        if(t1->getSize() < cacheSize){
            b1->removePage(page);
            replace(page);
        }
        else
            t1->removePage(page);
    }
    else{
        int size = t1->getSize() + t2->getSize() + b1->getSize() + b2->getSize();
        
        if(size >= cacheSize){
            if(size ==  2 * cacheSize)
                b2->removePage(page);

            replace(page);
        }
    }
    
    t1->add(page);    
    numMisses++;
    
    return true;
}

void ARC::adjust(int page, Adjustment adjType){
    int adj;
    
    if(adjType == MIN){
        if(b1->getSize() >= b2->getSize())
            adj = 1;
        else{
            if(b1->getSize() > 0)
                adj = b2->getSize()/b1->getSize();
            else
                adj = cacheSize;
        }
        
        p = std::min((p + adj), cacheSize);
    }
    else{
        if(b2->getSize() >= b1->getSize())
            adj = 1;
        else{
            if(b2->getSize() > 0)
                adj = b1->getSize()/b2->getSize();
            else
                adj = 0;
        }
        
        p = std::max((p - adj), 0);
    }
}

float ARC::getHitRatio(){
    calculateHitRatio();
    
    return hitRatio;
}

void ARC::calculateHitRatio(){
    hitRatio = (float)numHits/(float)numRequests * 100;
}

void ARC::replace(int page){
    if(t1->getSize() > 0 && (t1->getSize() > p || (b2->contains(page) && t1->getSize() == p))){
        t1->removePage(page);
        b1->add(page);
    }
    else{
        t2->removePage(page);
        b2->add(page);
    }
}