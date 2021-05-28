# Template Matching

## Requirements
Installing openCV for Microsoft Visual Studio. You can use the following guide: \
https://www.deciphertechnic.com/install-opencv-with-visual-studio/


## What is template matching?
Template matching is a technique for finding areas of an image that match (are similar) to a template image (patch).


## How does it work?
We need two primary components:
- Source image (I): The image in which we expect to find a match to the template image.
- Template image (T): The patch image will be compared to the source image our goal is to detect the highest matching area.

To identify the matching area, we have to compare the template image against the source image by sliding it. By sliding, we mean moving the patch one pixel at a time (left to right, up to down). At each location, a metric is calculated so it represents how "good" or "bad" the match at that location is (or how similar the patch is to that particular area of the source image).
For each location of T over I, you store the metric in the result matrix R. Each location (x,y) in R contains the match metric. In this example, the result R is of sliding the patch with a metric TM_CCORR_NORMED. The brightest locations indicate the highest matches. In practice, we locate the highest value in the R matrix, using the function minMaxLoc().

#### Recommendation
Save the input images (source and template images) under the same directory where the code is located.


## Results
#### Source image:
<p align="center">
  <img src="sorce_image.jpg">
</p>

#### Template image:
<p align="center">
  <img src="template_image.jpg">
</p>

#### Template Matching Result:
<p align="center">
  <img src="result_image.jpg">
</p>
