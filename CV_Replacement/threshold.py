""" https://docs.opencv.org/master/d7/d1b/group__imgproc__misc.html#gae8a4a146d1ca78c626a53577199e9c57

double cv::threshold 	( 	InputArray  	src,
		OutputArray  	dst,
		double  	thresh,
		double  	maxval,
		int  	type 
	) 		
Python:
	retval, dst	=	cv.threshold(	src, thresh, maxval, type[, dst]	)

#include <opencv2/imgproc.hpp>

Applies a fixed-level threshold to each array element.

The function applies fixed-level thresholding to a multiple-channel array. The function is typically used to get a bi-level (binary) image out of a grayscale image ( compare could be also used for this purpose) or for removing a noise, that is, filtering out pixels with too small or too large values. There are several types of thresholding supported by the function. They are determined by type parameter.

Also, the special values THRESH_OTSU or THRESH_TRIANGLE may be combined with one of the above values. In these cases, the function determines the optimal threshold value using the Otsu's or Triangle algorithm and uses it instead of the specified thresh.

Note
    Currently, the Otsu's and Triangle methods are implemented only for 8-bit single-channel images.

Parameters
    src	input array (multiple-channel, 8-bit or 32-bit floating point).
    dst	output array of the same size and type and the same number of channels as src.
    thresh	threshold value.
    maxval	maximum value to use with the THRESH_BINARY and THRESH_BINARY_INV thresholding types.
    type	thresholding type (see ThresholdTypes).

Returns
    the computed threshold value if Otsu's or Triangle methods used.

 """

 