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
#include <string>
#include <fstream>
//#include <stdio.h>


void TestBoundingRect();
void TestImageConstructor();
void TestingBitmap();
Image TestingImageConstructor(char* filepath);
Image TestImgCVT(char* filepath);


int main(){

    char* filepath = "./SampleImages/1.bmp";
    //test();
    //TestBoundingRect();
    //TestingBitmap();
    //TestingImageConstructor(filepath);
    TestImgCVT(filepath);


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

void TestImageConstructor(){

    std::string readingpath = "../SampleImages/";
    std::string filename = "2.jpg";
    std::string fullInputPath = readingpath + filename;
    std::string writingpath = "../OutputImages/";
    std::string fullOutputPath = writingpath + filename;

    //char filepath[100] = "../SampleImages/2.jpg";

}

//The purpose of this function is to test what happens when I read a bitmap image
void TestingBitmap(){

    FILE* imageFile = fopen("./SampleImages/1.bmp","rb");

    if(imageFile == NULL)
        std::cout << "File opening error" << std::endl;

    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54 , imageFile);
    
    //Extract information from the header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    std::cout << std::endl;
    std::cout << " Width: " << width << std::endl;
    std::cout << "Height: " << height << std::endl;

    int row_padded = (width*3+3)&(~3);
    unsigned char* data = new unsigned char[row_padded];
    unsigned char tmp;

    for(int i = 0; i < height; i++)
    {
        fread(data,sizeof(unsigned char), row_padded, imageFile);
        for(int j = 0; j < width *3; j += 3){
            //convert BGR to RGB
            tmp = data[j];
            data[j] = data[j+2];
            data[j+2] = tmp;

            std::cout << "R: "<< (int)data[j] << " G: " << (int)data[j+1]<< " B: " << (int)data[j+2]<< std::endl;

        }
    }

    fclose(imageFile);
    return;
}

Image TestingImageConstructor(char* filepath){
    std::cout << "Reached TestingImageConstructor Function" << std::endl;
    Image* ImageTest = new Image(filepath);
    //ImageTest.printBinary;

    std::cout << "Returned from ImageConstructor " << std::endl;
    return *ImageTest;
}

Image TestImgCVT(char* filepath){

    Image Image1 = TestingImageConstructor(filepath);
    Image1.cvtColor();
    return(Image1);

}