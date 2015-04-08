//
//  LRU.h
//  3
//
//  Created by Gregory Moon on 4/7/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#ifndef _____LRU__
#define _____LRU__

#include <stdio.h>
#include <list>

class LRU{
public:
    LRU(int cacheSize);
    ~LRU();
    
    void push_back(int page);
    bool contains(int page);
private:
    std::list<int> cache;
    int cacheSize;
};

#endif /* defined(_____LRU__) */
