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
}

LRU::~LRU(){
    
}

void LRU::push_back(int page){
    
}

bool LRU::contains(int page){
    std::list<int>::const_iterator it,
        itEnd = this->cache.end();
    
    for (it = this->cache.begin(); it != itEnd; it++) {
        printf("%d\n", *it);
    }
    
    return false;
}