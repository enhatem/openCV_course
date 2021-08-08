#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//////////////////// WARP PERSPECTIVES ////////////////////
int main(){

    float w = 250, h =350; // the size of a card is 2.5in x 3.5in. So, to keep the same aspect ratio, width = 250 and height = 350

    Mat matrix, imgWarp;

    string path = "Resources/cards.jpg";
    Mat img = imread(path); //Mat is a matrix data-type introduced by openCV to handle images
    
    Point2f src[4] = {{529,142}, {771,190}, {405,395}, {674,457}};  // the function we are going to use requires floating points. This is why Point2f was used.
                                                                    // these are the 4 corner points of the king card collected from the image
    Point2f dst[4] = {{0.0f,0.0f}, {w, 0.0f}, {0.0f, h}, {w,h}}; // destination points

    matrix = getPerspectiveTransform(src,dst);
    warpPerspective(img,imgWarp,matrix,Point(w,h));

    // drawing circles on the selected pixels
    for (int i = 0; i<4; i++)
    {
        circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
    }

    imshow("Image",img);
    imshow("Image Warped",imgWarp);
    waitKey(0);
    return 0;
}