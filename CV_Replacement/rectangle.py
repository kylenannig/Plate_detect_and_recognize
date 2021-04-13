""" https://docs.opencv.org/master/d6/d6e/group__imgproc__draw.html#ga07d2f74cadcf8e305e810ce8eed13bc9

void cv::rectangle 	( 	InputOutputArray  	img,
		Point  	pt1,
		Point  	pt2,
		const Scalar &  	color,
		int  	thickness = 1,
		int  	lineType = LINE_8,
		int  	shift = 0 
	) 		
Python:
	img	=	cv.rectangle(	img, pt1, pt2, color[, thickness[, lineType[, shift]]]	)
	img	=	cv.rectangle(	img, rec, color[, thickness[, lineType[, shift]]]	)

#include <opencv2/imgproc.hpp>

Draws a simple, thick, or filled up-right rectangle.

The function cv::rectangle draws a rectangle outline or a filled rectangle whose two opposite corners are pt1 and pt2.

Parameters
    img	Image.
    pt1	Vertex of the rectangle.
    pt2	Vertex of the rectangle opposite to pt1 .
    color	Rectangle color or brightness (grayscale image).
    thickness	Thickness of lines that make up the rectangle. Negative values, like FILLED, mean that the function has to draw a filled rectangle.
    lineType	Type of the line. See LineTypes
    shift	Number of fractional bits in the point coordinates. 
     """

     



//Draws a rectangle on the image provided.
//Destructive to the image provided, recommended to clone / copy first.

void cv::rectangle()