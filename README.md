# Adaptive Binarization using the Integral image

## Introduction
This is an c++ implementation of the article[1] which authors proposed a fast algorithm for adaptive image binarizaiton using the integral image[2].   
<div>
<img src='https://github.com/ComputerVisionIsFun/adaptive_binarization/blob/main/test.png' width=300 style='left'>
<img src='https://github.com/ComputerVisionIsFun/adaptive_binarization/blob/main/test_result.png' width=300 style='right'>
</div>

* The function integralImg in the integral_img.cpp computes the integral image of a given graylevel image. 
* The function adativeBinarization in the adativeBinarization.cpp does the binarization for a given grayscale image. 
* main.cpp is the sample code.   

## Reference 

<ul>[1] D. Bradley, G. Roth Adaptive thresholding using the integral image Journal of Graphics, GPU, and Game Tools, 12 (2) (2007), pp. 13-21.</ul>
<ul>[2] P.A. Viola, M.J. Jones, Rapid object detection using a boosted cascade of simple features, in: CVPR, issue 1, 2001, pp. 511–518.</ul>
 
