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

#include "jpeglib.h" //Note: Installed with: sudo apt-get install libjpeg-dev
#include <setjmp.h>
//#include <stdio.h>


void TestBoundingRect();
void TestImageConstructor();
void put_scanline_someplace(JSAMPARRAY buffer[0],int row_stride);

int main(){

    //test();
    //TestBoundingRect();
    TestImageConstructor();
    
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




struct my_error_mgr{
    struct jpeg_error_mgr pub;
    jmp_buf setjmp_buffer;
};

typedef struct my_error_mgr * my_error_ptr;

METHODDEF(void)
my_error_exit (j_common_ptr cinfo){
    my_error_ptr myerr = (my_error_ptr) cinfo -> err;
    (*cinfo->err->output_message)(cinfo);
    longjmp(myerr->setjmp_buffer,1);
}


//Function made by following the second half of: https://github.com/LuaDist/libjpeg/blob/master/example.c
void ReadJPEGFile(char * filename){

    struct jpeg_decompress_struct cinfo;
    struct my_error_mgr jerr;

    FILE * infile;      //Source File
    JSAMPARRAY buffer;  //Output row buffer
    int row_stride;     //physical row width in output buffer

    if((infile = fopen(filename, "rb")) == NULL){ //Note this should be "b" if we need a binary file
        fprintf(stderr, "can't open %s\n", filename);
        return;
    }

    //Step 1: Allocate and initialize JPEG decompression object

    cinfo.err = jpeg_std_error(&jerr.pub);
    jerr.pub.error_exit = my_error_exit;

    //Check if we need to exit due to error.
    if(setjmp(jerr.setjmp_buffer)){
        jpeg_destroy_decompress(&cinfo);
        fclose(infile);
        return;
    }

    //Initialize the JPEG decompression object
    jpeg_create_decompress(&cinfo);

    //Step 2: Specify data source
    jpeg_stdio_src(&cinfo,infile);

    //Step3: read file parameters with jpeg_read_header
    (void) jpeg_read_header(&cinfo,TRUE);

    //Step 4: Set parameters for decompression
    //Not necessary

    //Step 5: Decompress

    (void) jpeg_start_decompress(&cinfo);

    //JSAMPLEs per row in output buffer
    row_stride = cinfo.output_width * cinfo.output_components;
    //Make a one-row-high sample array that will go away when done with the image
    buffer = (*cinfo.mem->alloc_sarray)((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride,1);

    //Step 6: While there are scan lines, read them

    while(cinfo.output_scanline < cinfo.output_height){
        (void) jpeg_read_scanlines(&cinfo,buffer,1);

        put_scanline_someplace(buffer[0], row_stride);
    }

    //Step 7: Finish decompression
    (void) jpeg_finish_decompress(&cinfo);

    jpeg_destroy_decompress(&cinfo);

    fclose(infile);

    return;

}

void put_scanline_someplace(JSAMPARRAY buffer[0],int row_stride){

    return;
}