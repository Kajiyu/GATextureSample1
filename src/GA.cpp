//
//  GA.cpp
//  GATextureSample1
//
//  Created by KajiharaYuma on 2016/11/21.
//
//

#include "GA.h"

void GA::initialize(ofImage &image) {
    for (int i = 0; i < SAMPLENUM; i++) {
        vector<float> tmp;
        for (int j = 0; j < GENENUM; j++){
            tmp.push_back(ofRandom(1.0f));
        }
        samples.push_back(tmp);
        scores[i] = 0.0f;
        ofLoadImage(pixels[i], "ans.jpg");
    }
    ofPixels pixels = image.getPixelsRef();
    int w = pixels.getWidth();
    int h = pixels.getHeight();
    cout << w << " : " << h << endl;
    if (w != 100 || h != 100) {
        cout << "100×100にresizeしてね☆" << endl;
        return;
    } else {
        for(int i = 0; i < GENENUM; i++) {
            float color = ofMap(pixels.getColor(i).r, 0, 255, 0, 1.0f);
            cout << color << endl;
            ans[i] = color;
        }
    }
    currentBestScore = 10000;
    cout << "Complited Initialize GA" << endl;
}

void GA::evaluate() {
    currentBestScore = 10000;
    eliteindex = 0;
    for (int i = 0; i < SAMPLENUM; i++) {
        float tmp = 0;
        for (int j = 0; j < GENENUM; j++) {
            float sabun = abs(ans[j] - samples[i][j]);
            sabun = sabun*sabun;
            tmp += sabun;
        }
        tmp = sqrt(tmp);
        scores[i] = tmp;
        if (scores[i] < currentBestScore) {
            eliteindex = i;
            currentBestScore = scores[i];
        }
//        cout << i << "番目：" << scores[i] << endl;
        cout << currentBestScore << endl;
    }
}

void GA::selection() {
    vector<vector<float>> new_samples;
    for (int i = 0; i < SAMPLENUM-5; i++) {
        vector<float> new_vec;
        int a = ofRandom(SAMPLENUM);
        while (a == eliteindex) {
            a = ofRandom(SAMPLENUM);
        }
        int b = ofRandom(SAMPLENUM);
        while (a == b || b == eliteindex) {
            b = ofRandom(SAMPLENUM);
        }
        int point = ofRandom(GENENUM);
        
        for (int j = 0; j < GENENUM; j++) {
            if (j <= point) {
                new_vec.push_back(samples[a][j]);
            } else {
                new_vec.push_back(samples[b][j]);
            }
        }
        new_samples.push_back(new_vec);
    }
    //elite selection（一番良い成績の者はそのまま複製される。）
    new_samples.push_back(samples[eliteindex]);
    new_samples.push_back(samples[eliteindex]);
    new_samples.push_back(samples[eliteindex]);
    new_samples.push_back(samples[eliteindex]);
    new_samples.push_back(samples[eliteindex]);
//    samples.clear();
    samples = new_samples;
}

void GA::mutation() {
    for (int i = 0; i < SAMPLENUM; i++) {
        for (int j = 0; j < GENENUM; j++) {
            int tmp = ofRandom(0, 10000);
            if (tmp % 10000 == 2) {
                samples[i][j] = ofRandom(1.0f);
            }
            ofColor color = ofColor(255*samples[i][j], 255);
            pixels[i].setColor(j*3, color);
        }
    }
}