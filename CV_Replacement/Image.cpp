#include "CV_Replacement.h"
#include <vector>
#include <iostream>

//Rect boundingRect(std::vector<Coordinate> points);

Image::Image(){

}

//Constructor for loading in from a filepath. Intended for testing.
Image::Image(char* filepath){
    //Code From:
    //https://stackoverflow.com/questions/9296059/read-pixel-value-in-bmp-file/38440684
    
    FILE* imageFile = fopen(filepath,"rb");

    if(imageFile == NULL)
        std::cout << "File opening error" << std::endl;

    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54 , imageFile);
    
    //Extract information from the header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    //std::cout << std::endl;
    //std::cout << " Width: " << width << std::endl;
    //std::cout << "Height: " << height << std::endl;

    int row_padded = (width*3+3)&(~3);

    std::cout << "Row Padded: " << row_padded << std::endl;

    unsigned char* data = new unsigned char[row_padded];
    unsigned char tmp;

    //Allocate the memory for the image
    this->imageArray = (unsigned char***) malloc(width*sizeof(unsigned char**));
    for(int i = 0; i < width; i++){
        this->imageArray[i] = (unsigned char **) malloc(height*sizeof(unsigned char*));
        for(int j = 0; j < height; j++){
            this-> imageArray[i][j] = (unsigned char *) malloc(3*sizeof(unsigned char));//assumed depth
        }
    }

    //std::cout << this->imageArray[27][2][4] << std::endl;
//*
    //With the memory allocated, we fill it.
    for(int i = 0; i < width; i++){
        fread(data,sizeof(unsigned char), row_padded,imageFile);
        for(int j = 0; j < height; j++){
            //Converting BGR to RGB, will have to confirm if this is necessary later
            imageArray[i][j][0] = data[j*3+2];
            imageArray[i][j][1] = data[j*3+1];
            imageArray[i][j][2] = data[j*3];
            std::cout << "RGB: " << (int)data[j*3+2] << " " << (int)data[j*3+1] << " " << (int)data[j*3] << std::endl;
            //std::cout << this->imageArray[i][j][0];
        }
    }
//*/
    //Print out the data in a similar fashion.
    /*
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
    //*/

    this->imageWidth = width;
    this->imageHeight = height;
    this->numChannels = 3;
    fclose(imageFile);
    return;
}

Image::Image(int width, int height, int channels){

}

Image::~Image(){

}

//Make the image grayscale. Will have to make a new bit of memory and free the previous array.
//0.299R, 0.587G,0.114B
void Image::cvtColor(){
    int height = this->imageHeight;
    int width = this->imageWidth;
    
    std::cout << "RGBValues: " << (int)this->imageArray[0][0][0] << std::endl;
    std::cout << "Height: " << height << "| Width: " << width << std::endl;



    unsigned char ** grayArray = (unsigned char**) malloc(width*sizeof(unsigned char*));
    for(int i = 0; i < width; i++){
        grayArray[i] = (unsigned char *) malloc(height*sizeof(unsigned char));
    }



    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            int red = (int) this->imageArray[i][j][0];
            int green = (int) this ->imageArray[i][j][1];
            int blue = (int) this ->imageArray[i][j][2];
            //std::cout << "Red: " << (int) red << " | Shifted: " << red*0.299 << std::endl;
            int grayness = (red*0.299 + green*0.587 + blue*0.114);
            std::cout << "Grayness: " << grayness << std::endl;
            grayArray[i][j] = grayness;
        }
    }
    //*
    int threshold = 100;
    std::cout << "----------------------------" << std::endl;
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            
            if(grayArray[j][i] > 200){
                std::cout << "4";
            }
            else if(grayArray[j][i] > 150){
                std::cout << "3";
            }
            else if(grayArray[j][i] > 100){
                std::cout << "2";
            }
            else if(grayArray[j][i] > 50){
                std::cout << "1";
            }
            else if(grayArray[j][i] > 10){
                std::cout << "0";
            }
            else{
                std::cout << " ";
            }


        }

        std::cout << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
    //*/
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



//Takes an image, Creates new, slightly smaller memory for the return image.
//Performs the kernal convolution on each pixel and returns the new image.
Image Image::GaussianBlur(){

    float blurKernal[7][7] = {
        {0.00000067,0.00002292,0.00019117,0.00038771,0.00019117,0.00002292,0.00000067},
        {0.00002292,0.00078633,0.00655965,0.01330373,0.00655965,0.00078633,0.00002292},
        {0.00019117,0.00655965,0.05472157,0.11098164,0.05472157,0.00655965,0.00019117},
        {0.00038771,0.01330373,0.11098164,0.22508352,0.11098164,0.01330373,0.00038771},
        {0.00019117,0.00655965,0.05472157,0.11098164,0.05472157,0.00655965,0.00019117},
        {0.00002292,0.00078633,0.00655965,0.01330373,0.00655965,0.00078633,0.00002292},
        {0.00000067,0.00002292,0.00019117,0.00038771,0.00019117,0.00002292,0.00000067} };

    //int originalX = this.imageWidth;
    //int originalY = this.imageHeight;
    
}

