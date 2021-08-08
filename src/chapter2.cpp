#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//////////////////// BASIC FUNCTIONS ////////////////////

int main(){
    string path = "Resources/glysa_pic.jpeg";
    Mat img = imread(path); //Mat is a matrix data-type introduced by openCV to handle images
    Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

    cvtColor(img,imgGray, COLOR_BGR2GRAY); // Converting image to grayscale
    GaussianBlur(img,imgBlur,Size(3,3),3,0); // Introduces Gaussian blur to the image 
    Canny(imgBlur,imgCanny,25, 75); // Finds edges using the Canny algorithm (common practice is to use blurred images when performing edge detection)

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3)); // the shape is MORPH_RECT(rectangular) and the size is 5x5 (if the size is increased, it will dilate more, and if we decrease it, it will dilate less, USE ODD NUMBERS ONLY) ==> We created a kernel that we can use with dialation
    dilate(imgCanny,imgDil,kernel); // increasing the thickness of the edges
    erode(imgDil,imgErode,kernel);  // decreasing the thickness of the edges

    imshow("Image",img);
    imshow("Image Gray",imgGray);
    imshow("Image Blur",imgBlur);
    imshow("Image Canny",imgCanny);
    imshow("Image Dilation",imgDil);
    imshow("Image Erode",imgErode);

    waitKey(0);
    return 0;
}