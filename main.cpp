//
//  main.cpp
//  3
//
//  Created by Gregory Moon on 4/7/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#include <iostream>

#include "LRU.h"

int main(int argc, const char * argv[]) {
    LRU *l1 = new LRU(atoi(argv[1]));

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
                printf("%d\n", requestNum);
            
            for(int i = startingBlock; i < lastBlock; i++)
                l1->add(i);
        }
    }
    else
        printf("Not open\n");
    
    printf("%.2f\n", l1->getHitRatio());
    return 0;
}
