#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void getContours(Mat imgDil, Mat img){

    vector<vector<Point>> contours; // vector which contains vectors that contain points
    vector<Vec4i> hierarchy; // vector that contains 4 integer values

    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    // drawContours(img, contours, -1, Scalar(250,0,255), 2); // -1 means that we are drawing all of the contours

    vector<vector<Point>> conPoly(contours.size()); // we know exactly the size of conPoly since it cannot exceed the size of the contours vector
    vector<Rect> boundRect(contours.size());        // we know exactly the size of conPoly since it cannot exceed the size of the contours vector
    string objectType;

    // filter out noise and finding the shape of each contour
    for (int i = 0; i< contours.size(); i++)
    {
        double area = contourArea(contours[i]);
        cout << area << endl;
        if (area > 1000)
        {
            // approximating the number of curves that the contour i has. If it has 4 curves ==> it is a rectangle or a square. If it has 3 ==> triangle. If polygons >> ==> It is a circle
            float peri = arcLength(contours[i],true); // calculating the perimeter using the contours and the boolen "true" is indicating that the contour is closed
            approxPolyDP(contours[i], conPoly[i], 0.02*peri, true); // finding the approximation of the curves
                                                                    // 0.02 is just a random number (we could have changed 0.02*peri to a fixed number instead)
            
            cout<<conPoly[i].size()<<endl; // number of corner points it has found in each contour approximation
            // Finding the coordinates of the bounding box at each filtered shape
            boundRect[i] = boundingRect(conPoly[i]);


            int objCor = (int) conPoly[i].size(); // extracts the number of corner points in each polygon approximation ( but must be converted into integer)

            if (objCor == 3) {objectType = "Triangle";}
            if (objCor == 4) 
            {
                float aspRatio =  (float) boundRect[i].width / (float) boundRect[i].height;
                cout<<"Aspect Ratio = " << aspRatio << endl;
                if (aspRatio > 0.95 && aspRatio < 1.05) {objectType = "Square";}
                else {objectType = "Rectangle";}
            }
            if (objCor > 4) {objectType = "Circle";}
            
            drawContours(img, conPoly, i, Scalar(250,0,255), 2);    // Draw only the contours that have areas larger than 1000 to filter out the noise
            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5); // Drawing the bounding box using the rectangle - boundRect[i].tl(): calls the top left point - boundRect[i].br(): calls the bottom right point
            putText(img,objectType, {boundRect[i].x,boundRect[i].y - 5}, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2); // Adding the text to indicate if the contour is a triangle, square, rectangle or circle


        }
    }
}

//////////////////// SHAPES/CONTOUR DETECTION ////////////////////
int main(){

    Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

    string path = "Resources/shapes.png";
    Mat img = imread(path); //Mat is a matrix data-type introduced by openCV to handle images
    
    // Preprocessing of the image
    cvtColor(img,imgGray, COLOR_BGR2GRAY); // Converting image to grayscale
    GaussianBlur(imgGray,imgBlur,Size(3,3),3,0); // Introduces Gaussian blur to the image 
    Canny(imgBlur,imgCanny,25, 75); // Finds edges using the Canny algorithm (common practice is to use blurred images when performing edge detection)
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3)); // the shape is MORPH_RECT(rectangular) and the size is 5x5 (if the size is increased, it will dilate more, and if we decrease it, it will dilate less, USE ODD NUMBERS ONLY) ==> We created a kernel that we can use with dialation
    dilate(imgCanny,imgDil,kernel); // increasing the thickness of the edges (to remove the gaps from the edges in the Canny image)

    // Now that the image has be preprocessed, we will now find the contours
    getContours(imgDil, img);

    imshow("Image", img);
    // imshow("Image Gray", imgGray);
    // imshow("Image Blur", imgBlur);
    // imshow("Image Canny", imgCanny);
    // imshow("Image Dil", imgDil);

    waitKey(0);
    return 0;
}