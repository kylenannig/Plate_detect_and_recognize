""" https://docs.opencv.org/master/d4/d86/group__imgproc__filter.html#gaabe8c836e97159a9193fb0b11ac52cf1

void cv::GaussianBlur 	( 	InputArray  	src,
		OutputArray  	dst,
		Size  	ksize,
		double  	sigmaX,
		double  	sigmaY = 0,
		int  	borderType = BORDER_DEFAULT 
	) 		
Python:
	dst	=	cv.GaussianBlur(	src, ksize, sigmaX[, dst[, sigmaY[, borderType]]]	)

#include <opencv2/imgproc.hpp>

Blurs an image using a Gaussian filter.

The function convolves the source image with the specified Gaussian kernel. In-place filtering is supported.

Parameters
    src	input image; the image can have any number of channels, which are processed independently, but the depth should be CV_8U, CV_16U, CV_16S, CV_32F or CV_64F.
    dst	output image of the same size and type as src.
    ksize	Gaussian kernel size. ksize.width and ksize.height can differ but they both must be positive and odd. Or, they can be zero's and then they are computed from sigma.
    sigmaX	Gaussian kernel standard deviation in X direction.
    sigmaY	Gaussian kernel standard deviation in Y direction; if sigmaY is zero, it is set to be equal to sigmaX, if both sigmas are zeros, they are computed from ksize.width and ksize.height, respectively (see getGaussianKernel for details); to fully control the result regardless of possible future modifications of all this semantics, it is recommended to specify all of ksize, sigmaX, and sigmaY.
    borderType	pixel extrapolation method, see BorderTypes. BORDER_WRAP is not supported. """

    