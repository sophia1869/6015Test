//
//  main.cpp
//  assignment3
//
//  Created by Hui Zhou on 1/17/19.
//  Copyright © 2019 Hui Zhou. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>
#include <string>

bool compareDouble (double d1, double d2){
    if (d1==d2)
        return true;
    // for some slope the divider may be 0 the d1 d2 given here is undefined and can not use the following comparison
    return (fabs(d1-d2))<(0.00001*fabs(d1));
}

std::string quadrilateralClassifier(double x1, double y1, double x2, double y2, double x3, double y3){
    
    int x0 = 0;
    int y0 = 0;
    
    double slope01 = (y1-y0)/(x1-x0);
    double length01 = sqrt( (x1-x0)*(x1-x0)+(y1-y0)*(y1-y0) );
    
    double slope32 = (y2-y3)/(x2-x3);
    double length32 = sqrt( (x2-x3)*(x2-x3)+(y2-y3)*(y2-y3) );
    
    double slope03 = (y3-y0)/(x3-x0);
    double length03 = sqrt( (x3-x0)*(x3-x0)+(y3-y0)*(y3-y0) );
    
    double slope12 = (y2-y1)/(x2-x1);
    double length12 = sqrt( (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) );
    
    
    bool para0132 = compareDouble(slope01,slope32);
    //    bool equallength0132 = compareDouble(length01, length32);
    
    bool para0312 = compareDouble(slope03, slope12);
    //    bool equallength0312 = compareDouble(length03, length12);
    
    bool equallength1232 = compareDouble(length12, length32);
    //    bool equallength0103 = compareDouble(length01, length03);
    
    bool isRec0 = compareDouble((y3-y1)*(y3-y1)+(x3-x1)*(x3-x1), length01*length01+length03*length03);
    //    bool isRec1 = compareDouble((y2-y0)*(y2-y0)+(x2-x0)*(x2-x0), length01*length01+length12*length12);
    //    bool isRec2 = compareDouble((y2-y3)*(y2-y3)+(x2-x3)*(x2-x3), length12*length12+length32*length32);
    //    bool isRec3 = compareDouble((y2-y0)*(y2-y0)+(x2-x0)*(x2-x0), length03*length03+length32*length32);
    
    if (para0132 && para0312 && equallength1232 && isRec0){
        std::cout<<"squares\n";
        return "squares";
    }
    
    if (para0132 && para0312 && equallength1232 ){
        std::cout<<"rhombi\n";
        return "rhombi";
    }
    
    if (para0132 && para0312 && isRec0){
        std::cout<<"rectangles\n";
        return "rectangles";
    }
    
    if (para0132 && para0312){
        std::cout<<"parallegograms\n";
        return "parallegograms";
    }
    
    if (para0132 || para0312){
        std::cout<<"trapezoids\n";
        return "parallegograms";
    }
    
    if (equallength1232){
        std::cout<<"kites\n";
        return "parallegograms";
    }
    else{
        std::cout<<"quadraliteral\n";
        return "parallegograms";
    }
    
}

int main(int argc, const char * argv[]) {
    
    //    quadrilateralClassifier(5,0,8,4,3,4);
    //    quadrilateralClassifier(5,0,8,3,3,3);
    //    quadrilateralClassifier(4,0,4,4,0,4);
    //    quadrilateralClassifier(4,0,4,5,0,5);
    //    quadrilateralClassifier(5,0,4,4,3,4);
    //    quadrilateralClassifier(3,9,10,10,9,3);
    //    quadrilateralClassifier(3,8,4,5,10,4);
    
    std::ifstream infile("data.txt");
    std::string line;
    
    while (getline(infile, line)){
        std::istringstream iss (line);
        int data0,data1,data2,data3,data4,data5;
        if (!(iss>>data0>>data1>>data2>>data3>>data4>>data5)) {
            break;
        }
        std::string res = quadrilateralClassifier(data0,data1,data2,data3,data4,data5);
        std::cout<<res<<std::endl;
    }
}
