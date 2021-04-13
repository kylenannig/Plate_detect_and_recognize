""" https://docs.opencv.org/master/d3/dc0/group__imgproc__shape.html#gadf1ad6a0b82947fa1fe3c3d497f260e0

void cv::findContours 	( 	InputArray  	image,
		OutputArrayOfArrays  	contours,
		OutputArray  	hierarchy,
		int  	mode,
		int  	method,
		Point  	offset = Point() 
	) 		
Python:
	contours, hierarchy	=	cv.findContours(	image, mode, method[, contours[, hierarchy[, offset]]]	)

#include <opencv2/imgproc.hpp>

Finds contours in a binary image.

The function retrieves contours from the binary image using the algorithm [228] . The contours are a useful tool for shape analysis and object detection and recognition. See squares.cpp in the OpenCV sample directory.

Note
    Since opencv 3.2 source image is not modified by this function.

Parameters
    image	Source, an 8-bit single-channel image. Non-zero pixels are treated as 1's. Zero pixels remain 0's, so the image is treated as binary . You can use compare, inRange, threshold , adaptiveThreshold, Canny, and others to create a binary image out of a grayscale or color one. If mode equals to RETR_CCOMP or RETR_FLOODFILL, the input can also be a 32-bit integer image of labels (CV_32SC1).
    contours	Detected contours. Each contour is stored as a vector of points (e.g. std::vector<std::vector<cv::Point> >).
    hierarchy	Optional output vector (e.g. std::vector<cv::Vec4i>), containing information about the image topology. It has as many elements as the number of contours. For each i-th contour contours[i], the elements hierarchy[i][0] , hierarchy[i][1] , hierarchy[i][2] , and hierarchy[i][3] are set to 0-based indices in contours of the next and previous contours at the same hierarchical level, the first child contour and the parent contour, respectively. If for the contour i there are no next, previous, parent, or nested contours, the corresponding elements of hierarchy[i] will be negative.
    mode	Contour retrieval mode, see RetrievalModes
    method	Contour approximation method, see ContourApproximationModes
    offset	Optional offset by which every contour point is shifted. This is useful if the contours are extracted from the image ROI and then they should be analyzed in the whole image context.


 """

 