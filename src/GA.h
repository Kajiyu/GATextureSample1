//
//  GA.h
//  GATextureSample1
//
//  Created by KajiharaYuma on 2016/11/21.
//
//

#pragma once
#include "ofMain.h"
#define SAMPLENUM 10
#define GENENUM 10000

class GA {
public:
    float ans[GENENUM];
    vector<vector<float>> samples;
    float scores[SAMPLENUM];
    ofPixels pixels[SAMPLENUM];
    float mutationPer = 0.01;
    float eliteNum = 1; //エリート選択に使う数
    int currentAge = 0;
    float currentBestScore = 0;
    int eliteindex;
    int maxAge = 30000;
    void initialize(ofImage &image);
    void evaluate();
    void selection();
    void mutation();
};