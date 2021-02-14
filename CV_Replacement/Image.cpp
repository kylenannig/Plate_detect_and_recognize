#include "CV_Replacement.h"
#include <vector>
#include <iostream>

//Rect boundingRect(std::vector<Coordinate> points);

Image::Image(){

}

Image::~Image(){

}


void Image::cvtColor(){

}

//Draws a box over the image using the rectangle as the bounds. Destructive.
void Image::Rectangle(Rect bounds, int thickness){

}

//From a vector of coordinates returns a rectangle encompasing all of the points.
//Error will return a rectangle of all -1s.
Rect Image::BoundingRect(std::vector<Coordinate> points){
    //IF VECTOR SIZE = 0 RETURN ERROR HERE
    if(points.size() == 0){
        std::cout << "No points in coordinate list. Error in 'boundingRect'" << std::endl;
        Rect *errorRect = new Rect(-1,-1,-1,-1);
        return(*errorRect);
    }


    //Set an initial value for our variables using the first given argument.
    int maxX = points[0].x;
    int maxY = points[0].y;
    int minX = points[0].x;
    int minY = points[0].y;

    //Loop through starting with the second element to find more extreme maximums or minimums
    int numberOfPoints = points.size();
    //std::cout << "Number of points: " << numberOfPoints << std::endl;
    //std::cout << "Vector: " << points[0].x << ", " << points[0].y << " | ";
    for(int i = 1; i < numberOfPoints; i++){
        
        std::cout << points[i].x << ", " << points[i].y << " | "; // << std::endl;

        if(points[i].x > maxX){
            maxX = points[i].x;
        }
        else if(points[i].x < minX){
            minX = points[i].x;
        }

        if(points[i].y > maxY){
            maxY = points[i].y;
        }
        else if(points[i].y < minY){
            minY = points[i].y;
        }

    }
    std::cout << std::endl;

    //std::cout << "Maximums: " << maxX << " , " << maxY << std::endl;
    //std::cout << "Minimums: " << minX << " , " << minY << std::endl; 

    Rect *boundingRect = new Rect(maxX,maxY,minX,minY);

    return(*boundingRect);
}