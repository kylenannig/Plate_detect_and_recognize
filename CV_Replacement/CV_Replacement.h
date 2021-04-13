//Cstyle Header File
//File created by Steven Anzivino 1/30/2021
//Class: Capstone  | On behalf of XMOS

#pragma once

#ifndef CV_REPLACEMENT_H
#define CV_REPLACEMENT_H

//AFAIK includes should not be in header files, will move.
//#include <stdio.h>
#include <vector>

/////void cvtColor();
///Image GaussianBlur();
double threshold();
//Mat getStructuringElement();
void morphologyEx();
//rect boundingRect();
void findContours();
/////void rectangle();
//test();


class Coordinate{
    public:
        Coordinate(int xCoordinate, int yCooridnate);
        ~Coordinate();
        int x;
        int y;
};

class Rect{
    public:
        Rect(int xCoordinate1, int yCoordinate1, int xCoordinate2, int yCoordinate2);
        Rect(Coordinate Coord1, Coordinate Coord2);
        ~Rect();
        int x1;
        int y1;
        int x2;
        int y2;
};

class Image
{
    public:
    Image();
    Image(char* filepath);
    Image(int width, int height, int channels);
    ~Image();
    //make the image grayscale. Destructive.
    void cvtColor();
    
    //void Rectangle( InputOutputArray img, Point pt1, Point pt2, const Scalar & color, int thickness = 1, int lineType = LINE_8, int shift = 0 ); 
    //Draws a rectangle on the image. Destructive.
    void Rectangle(Rect bounds, int thickness);


    //From a vector of coordinates returns a rectangle encompasing all of the points.
    Rect BoundingRect(std::vector<Coordinate> CoordinateVector);

    //Performs a hardcoded GaussianBlur on this image (assuming grayscale) and returns a new blurred image
    //Currently implemented as a for loop, without utilizing the board's convolution, cuts off 3 pixels from each edge
    Image GaussianBlur();







    private:

    unsigned int imageWidth;
    unsigned int imageHeight;
    unsigned int numChannels;

    unsigned char *** imageArray;

};



#endif