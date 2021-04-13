""" https://docs.opencv.org/master/d4/d86/group__imgproc__filter.html#ga67493776e3ad1a3df63883829375201f

void cv::morphologyEx 	( 	InputArray  	src,
		OutputArray  	dst,
		int  	op,
		InputArray  	kernel,
		Point  	anchor = Point(-1,-1),
		int  	iterations = 1,
		int  	borderType = BORDER_CONSTANT,
		const Scalar &  	borderValue = morphologyDefaultBorderValue() 
	) 		
Python:
	dst	=	cv.morphologyEx(	src, op, kernel[, dst[, anchor[, iterations[, borderType[, borderValue]]]]]	)

#include <opencv2/imgproc.hpp>

Performs advanced morphological transformations.

The function cv::morphologyEx can perform advanced morphological transformations using an erosion and dilation as basic operations.

Any of the operations can be done in-place. In case of multi-channel images, each channel is processed independently.

Parameters
    src	Source image. The number of channels can be arbitrary. The depth should be one of CV_8U, CV_16U, CV_16S, CV_32F or CV_64F.
    dst	Destination image of the same size and type as source image.
    op	Type of a morphological operation, see MorphTypes
    kernel	Structuring element. It can be created using getStructuringElement.
    anchor	Anchor position with the kernel. Negative values mean that the anchor is at the kernel center.
    iterations	Number of times erosion and dilation are applied.
    borderType	Pixel extrapolation method, see BorderTypes. BORDER_WRAP is not supported.
    borderValue	Border value in case of a constant border. The default value has a special meaning. 

 """

 