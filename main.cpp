//
//  main.cpp
//  3
//
//  Created by Gregory Moon on 4/7/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#include <iostream>

#include "ARC.h"

int main(int argc, const char * argv[]) {
    ARC *arc = new ARC(atoi(argv[1]));
    LRU *lru = new LRU(atoi(argv[1]));
    
    FILE *inFile = fopen(argv[2], "r");
    
    if(inFile != NULL){
        int startingBlock, numBlocks, ignore, requestNum;
       
        while(!feof(inFile)){
            fscanf(inFile, "%d", &startingBlock);
            fscanf(inFile, "%d", &numBlocks);
            fscanf(inFile, "%d", &ignore);
            fscanf(inFile, "%d", &requestNum);
            
            int lastBlock = startingBlock + numBlocks;
            
            if(requestNum % 100000 == 0)
                printf("Processed %d entries\n", requestNum);
            
            for(int i = startingBlock; i < lastBlock; i++){
                arc->add(i);
                lru->add(i);
            }
	}
    }
    else
        printf("Not open\n");
    
    printf("arc hit ratio: %.2f\n", arc->getHitRatio());
    printf("lru hit ratio: %.2f\n", lru->getHitRatio());
    
    return 0;
}
