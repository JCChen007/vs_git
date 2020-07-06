#include <iostream>
#include<string>
#include<sstream>
using namespace std;


//#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include<opencv2/highgui.hpp>
#include <opencv2/aruco.hpp>
//#include <stdio.h>
//using namespace cv;


//int main(int argc, char* argv[])
int main()
{
    cv::Mat markerimage;
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);

    //cv::aruco::drawMarker(dictionary, 51, 200, markerimage, 1);
    //cv::imwrite("marker51.png", markerimage);
    //cv::imshow("maker", markerimage);
    //cv::waitKey(0);
    for (int i = 1; i <= 3; i++)
    {
        ostringstream ss;
        ss << "maker" << i << ".png";
        cv::aruco::drawMarker(dictionary, i, 200, markerimage, 1);
        cv::imwrite(ss.str(), markerimage);
        cv::imshow(ss.str(), markerimage);

    }
    cv::waitKey(0);


    //cv::Mat inputImage=cv::imread("newmakers.jpg");
    ////cv::imshow("maker", inputImage);
    ////cv::waitKey(0);
    //std::vector<int> markerIds;
    //std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
    //cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
    //cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    //cv::aruco::detectMarkers(inputImage, dictionary, markerCorners, markerIds, parameters, rejectedCandidates);
    //cv::Mat outputImage = inputImage.clone();
    //cv::aruco::drawDetectedMarkers(outputImage, markerCorners, markerIds);
    //cv::imshow("out", outputImage);
    //cv::waitKey(0);
    //cv::imwrite("dection.jpg", outputImage);

    return 0;
}