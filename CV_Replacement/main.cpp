//C style main file
//File created by Steven Anzivino 1/30/2021
//Class: Capstone  | On behalf of XMOS

//To compile:
//clang++ main.cpp Coordinate.cpp Rect.cpp Image.cpp -I CV_Replacement.h -o main
//


#include "CV_Replacement.h"
#include <vector>
#include <iostream>
#include <time.h> //For seeding the random generator for testing


void TestBoundingRect();

int main(){

    //test();
    //TestBoundingRect();
    
    return 0;
}


void TestBoundingRect(){
    
    int desiredPoints = 5;
    int XLimit = 15;
    int YLimit = 20;

    //Makes a coordinate
    std::vector<Coordinate> points;
    Coordinate *tempCoordinates = new Coordinate(0,0);
   
   //Fills a vector with <desiredPoints> worth of randomized X and Y value pairs.
    srand(time(0));
    for(int i = 0; i < desiredPoints; i++){

        //Generates between 0 and limit.
        tempCoordinates->x = rand() % XLimit;
        tempCoordinates->y = rand() % YLimit;

        points.push_back(*tempCoordinates);
        //std::cout << "Coordinate??? " + points[i].x + ", " + points[i].y << std::endl;
    }
    
    //Create a blank image for testing purposes
    Image *testingImage = new Image();

    //
    Rect boundingRect = testingImage->BoundingRect(points);

    std::cout << "Bounding Rect points: " << "MX: " << boundingRect.x1 << ", MY: " << boundingRect.y1 << ", mX: " << boundingRect.x2 << ", mY: " << boundingRect.y2 << std::endl;

    return;
}
