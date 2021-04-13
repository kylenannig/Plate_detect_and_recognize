""" https://docs.opencv.org/master/d4/d86/group__imgproc__filter.html#gac342a1bb6eabf6f55c803b09268e36dc

Mat cv::getStructuringElement 	( 	int  	shape,
		Size  	ksize,
		Point  	anchor = Point(-1,-1) 
	) 		
Python:
	retval	=	cv.getStructuringElement(	shape, ksize[, anchor]	)

#include <opencv2/imgproc.hpp>

Returns a structuring element of the specified size and shape for morphological operations.

The function constructs and returns the structuring element that can be further passed to erode, dilate or morphologyEx. But you can also construct an arbitrary binary mask yourself and use it as the structuring element.

Parameters
    shape	Element shape that could be one of MorphShapes
    ksize	Size of the structuring element.
    anchor	Anchor position within the element. The default value (−1,−1) means that the anchor is at the center. Note that only the shape of a cross-shaped element depends on the anchor position. In other cases the anchor just regulates how much the result of the morphological operation is shifted.  """

    