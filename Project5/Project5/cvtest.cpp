#include <iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;


#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include<opencv2/highgui.hpp>
#include <opencv2/aruco.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio.hpp> 
using namespace cv;


//int main(int argc, char* argv[])
int main()
{
 ////����aruco maker 
 //   cv::Mat markerimage;
 //   cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);

 //   //cv::aruco::drawMarker(dictionary, 51, 200, markerimage, 1);
 //   //cv::imwrite("marker51.png", markerimage);
 //   //cv::imshow("maker", markerimage);
 //   //cv::waitKey(0);
 //   for (int i = 1; i <= 100; i++)
 //   {
 //       ostringstream ss;
 //       ss << "maker" << i << ".png";
 //       cv::aruco::drawMarker(dictionary, i, 200, markerimage, 1);
 //       cv::imwrite(ss.str(), markerimage);
 //       cv::imshow(ss.str(), markerimage);

 //   }
 //   cv::waitKey(0);

//ʶ��ͼaruco maker 
    //double start = static_cast<double>(getTickCount());
    //cv::Mat inputImage=cv::imread("new100maker.png");
    ////cv::imshow("maker", inputImage);
    ////cv::waitKey(0);
    //std::vector<int> markerIds;
    //std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
    //cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
    //cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    //cv::aruco::detectMarkers(inputImage, dictionary, markerCorners, markerIds, parameters, rejectedCandidates);
    //cv::Mat outputImage = inputImage.clone();
    //cv::aruco::drawDetectedMarkers(outputImage, markerCorners, markerIds);
    //double end = static_cast<double>(getTickCount());
    //double run_time = (end - start) / getTickFrequency();
    //cout << "run_time=" << run_time << " seconds" << endl;
    //cv::imshow("detectionimage", outputImage);
    //cv::waitKey(0);
    //cv::imwrite("dection100.jpg", outputImage);

    //��ȡ��Ƶ�ļ�
//  cv::namedWindow("example",cv::WINDOW_AUTOSIZE);
//  cv::VideoCapture cap;
//  cap.open("movie1.mp4");
//  cv::Mat frame;
//while(1)
//  {
//      cap >> frame;
//      if (frame.empty())  break;
//      cv::imshow("video", frame);
//      if (cv::waitKey(33) >= 0) break;
//  }



    //ʶ����Ƶaruco maker
    cv::Mat frame;
    //cv::namedWindow("example", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap("test2.mp4");
    cap.set(CAP_PROP_EXPOSURE,-8);//�����ع�ʱ��
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 1984);//���ö���ֱ���
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 1264);
    //int ex = static_cast<int>(cap.get(CAP_PROP_FOURCC));
    //char EXT[] = {ex&0XFF,(ex&0XFF00)>>8,(ex&0XFF0000)>>16,(ex&0XFF000000)>>24,0};
    //cap.open("movie1.mp4"); 
    // ��ȡ������Ƶ�Ŀ����߶�
    //int width = (int)cap.get(cv::CAP_PROP_FRAME_WIDTH);
    //int height = (int)cap.get(CAP_PR��P_FRAME_HEIGHT);
    VideoWriter out;
    out.open("outputtest2.mpg",
        //CAP_OPENCV_MJPEG,
        VideoWriter::fourcc('D', 'I', 'V', 'X'),
        //ex,
        //cap.get(CAP_PROP_FPS), //��ȡ֡��
        20,
        cv::Size((int)cap.get(CAP_PROP_FRAME_WIDTH),(int)cap.get(CAP_PROP_FRAME_HEIGHT)),
        true);
    if (!cap.isOpened())
    {
        cout << "Video load failed!" << endl;
        return -1;
    }
    if (!out.isOpened())
    {
        cout << "Video writer failed!" << endl;
        return -2;
    }
    while (1)
    { 
       //��ȡ��Ƶ
       cap >> frame;
       if (frame.empty())  break;
       //cv::imshow("video", frame);
       //if (cv::waitKey(33) >= 0) break;

       //ʶ��aruco maker
       std::vector<int> markerIds;
       std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
       cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
       cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
       cv::aruco::detectMarkers(frame, dictionary, markerCorners, markerIds, parameters, rejectedCandidates);
       cv::Mat outImage = frame.clone();
       cv::aruco::drawDetectedMarkers(outImage, markerCorners, markerIds);
       //cv::imshow("outvideo", outputImage);
       //if (cv::waitKey(33) >= 0) break;
       //cv::imwrite("dection.jpg", outputImage);
       out << outImage;
       //imshow("inputvideo", frame);
       //imshow("outputvideo", outImage);
       //if (waitKey(37) >= 0) break;
    }

    cap.release();

    return 0;

}