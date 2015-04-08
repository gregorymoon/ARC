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
#include <unordered_map>

class LRU{
public:
    LRU(int cacheSize);
    ~LRU();
    
    void add(int page);
    float getHitRatio();
private:
    std::list<int> cache;
    std::unordered_map<int, bool> currPages;
    std::unordered_map<int, std::list<int>::iterator> itLocs;
    int cacheSize, numHits, numRequests;
    float hitRatio;
    
    bool contains(int page);
    void calculateHitRatio();
    void moveToBack(int page);
    void replacePage(int page);
};

#endif /* defined(_____LRU__) */
