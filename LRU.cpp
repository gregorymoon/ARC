//
//  LRU.cpp
//  3
//
//  Created by Gregory Moon on 4/7/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#include "LRU.h"

LRU::LRU(int cacheSize){
    this->cacheSize = cacheSize;
    numHits = 0;
    numRequests = 0;
    
    containsTime = 0;
    calculateTime = 0;
    moveTime = 0;
    replaceTime = 0;
}

LRU::~LRU(){
    
}

void LRU::add(int page){
    numRequests++;
    
    if(contains(page))
        moveToBack(page);
    else{
        if(cache.size() < cacheSize){
            cache.push_back(page);
            currPages[page] = true;
        }
        else
            replacePage(page);
    }
}

bool LRU::contains(int page){
    clock_t start = clock();
    
    if(currPages[page]){
        numHits++;
        return true;
    }

    double duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    containsTime += duration;
    
    return false;
}

float LRU::getHitRatio(){
    calculateHitRatio();
    
    double totalTime = moveTime + replaceTime + calculateTime + containsTime;
    printf("Move Time = %.2f: %.2f of total\n", moveTime, moveTime/totalTime);
    printf("Replace Time = %.2f: %.2f of total\n", replaceTime, replaceTime/totalTime);
    printf("Calculate Time = %.2f: %.2f of total\n", calculateTime, calculateTime/totalTime);
    printf("Contains Time = %.2f: %.2f of total\n", containsTime, containsTime/totalTime);
    printf("Total Time = %.2f\n", totalTime);


    return hitRatio;
}

void LRU::calculateHitRatio(){
    clock_t start = clock();
    
    hitRatio = (float)numHits/(float)numRequests * 100;
    
    double duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    calculateTime += duration;
}

void LRU::moveToBack(int page){
    clock_t start = clock();
    
    cache.remove(page);
    cache.push_back(page);
    
    double duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    moveTime += duration;
}

void LRU::replacePage(int page){
    clock_t start = clock();
    
    int oldPage = cache.front();
    
    //currPages.erase(oldPage);
    currPages[oldPage] = false;
    currPages[page] = true;
    
    cache.pop_front();
    cache.push_back(page);
    
    double duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    replaceTime += duration;
}