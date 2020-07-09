#include <iostream>
#include<string>
#include<sstream>
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
    ////生成aruco maker 
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

   //识别单图aruco maker 
    double start = static_cast<double>(getTickCount());

    cv::Mat inputImage = cv::imread("new100makers.png");

    //Mat calibrationImage = inputImage.clone();//存储矫正后的图片
    //Mat camera_matrix = Mat(3, 3, CV_32FC1);
    //Mat distortion_coefficients;


    ////导入相机内参和畸变系数矩阵
    //FileStorage file_storage("out_camera_data.xml", FileStorage::READ);
    //file_storage["camera_matrix"] >> camera_matrix;
    //file_storage["distortion_coefficients"] >> distortion_coefficients;
    //file_storage.release();

    ////矫正
    //undistort(inputImage, calibrationImage,camera_matrix, distortion_coefficients);
    //cv::imshow("maker", inputImage);
    //cv::imshow("calibration", calibrationImage);
    //cv::imwrite("calibration.jpg", calibrationImage);
    //cv::waitKey(0);

    std::vector<int> markerIds;
    std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
    cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    cv::aruco::detectMarkers(inputImage, dictionary, markerCorners, markerIds, parameters, rejectedCandidates);
    cv::Mat outputImage = inputImage.clone();
    cv::aruco::drawDetectedMarkers(outputImage, markerCorners, markerIds);
    double end = static_cast<double>(getTickCount());
    double run_time = (end - start) / getTickFrequency();
    cout << "run_time=" << run_time << " seconds" << endl;
    cv::imshow("detectionimage", outputImage);
    cv::waitKey(0);
    cv::imwrite("dection100.jpg", outputImage);

    //读取视频文件
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



    ////识别视频aruco maker
    //double start = static_cast<double>(getTickCount());
    //cv::Mat frame;
    ////cv::namedWindow("example", cv::WINDOW_AUTOSIZE);
    //cv::VideoCapture cap(0);
    ////cap.set(CAP_PROP_EXPOSURE, -8);//设置曝光时间
    //cap.set(cv::CAP_PROP_FRAME_WIDTH, 1984);//设置读入分辨率1984X1264
    //cap.set(cv::CAP_PROP_FRAME_HEIGHT, 1264);
    ////int ex = static_cast<int>(cap.get(CAP_PROP_FOURCC));
    ////char EXT[] = { ex & 0XFF,(ex & 0XFF00) >> 8,(ex & 0XFF0000) >> 16,(ex & 0XFF000000) >> 24,0 };
    ////cap.open(0); 
    //// 获取输入视频的宽度与高度
    ////int width = (int)cap.get(cv::CAP_PROP_FRAME_WIDTH);
    ////int height = (int)cap.get(CAP_PR〇P_FRAME_HEIGHT);
    //VideoWriter out;
    //out.open("calibration_outputtest.mp4",
    //    //CAP_OPENCV_MJPEG,
    //    VideoWriter::fourcc('D', 'I', 'V', 'X'),
    //    //ex=-1,
    //    //cap.get(CAP_PROP_FPS), //获取帧率
    //    5,
    //    cv::Size((int)cap.get(CAP_PROP_FRAME_WIDTH), (int)cap.get(CAP_PROP_FRAME_HEIGHT)),
    //    true);
    //if (!cap.isOpened())
    //{
    //    cout << "camera load failed!" << endl;
    //    return -1;
    //}
    //if (!out.isOpened())
    //{
    //    cout << "camera writer failed!" << endl;
    //    return -2;
    //}
    //int count = 0;
    //while (1)
    //{
    //    //读取摄像头
    //    cap >> frame;
    //    if (frame.empty())  break;
    //    /* cv::imshow("video", frame);
    //     if (cv::waitKey(33) >= 0) break;*/
    //     //cap.read(frame);
    //     //识别aruco maker
    //    Mat calibrationframe = frame.clone();//存储矫正后的图片
    //    Mat camera_matrix = Mat(3, 3, CV_32FC1);
    //    Mat distortion_coefficients;


    //    //导入相机内参和畸变系数矩阵
    //    FileStorage file_storage("out_camera_data.xml", FileStorage::READ);
    //    file_storage["camera_matrix"] >> camera_matrix;
    //    file_storage["distortion_coefficients"] >> distortion_coefficients;
    //    file_storage.release();

    //    //矫正
    //    undistort(frame, calibrationframe, camera_matrix, distortion_coefficients);

    //    ++count;
    //    std::vector<int> markerIds;
    //    std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
    //    cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
    //    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    //    //cv::aruco::detectMarkers(calibrationframe, dictionary, markerCorners, markerIds, parameters, rejectedCandidates);
    //    cv::aruco::detectMarkers(calibrationframe, dictionary, markerCorners, markerIds);
    //    cv::Mat outImage = calibrationframe.clone();
    //    cv::aruco::drawDetectedMarkers(outImage, markerCorners, markerIds);
    //    //cv::imshow("outvideo", outputImage);
    //    //if (cv::waitKey(33) >= 0) break;
    //    //cv::imwrite("dection.jpg", outputImage);
    //   //namedWindow("inputvideo", WINDOW_FREERATIO);
    //    // namedWindow("calibrationvideo", WINDOW_FREERATIO);
    //    namedWindow("outputvideo", WINDOW_FREERATIO);

    //    // imshow("inputvideo", frame);
    //     //imshow("calibrationvideo", calibrationframe);
    //    imshow("outputvideo", outImage);
    //    //out.write(outImage);
    //    out << outImage;
    //    if (waitKey(60) >= 0) break;
    //}
    //cout << "总帧数" << count << endl;
    //double end = static_cast<double>(getTickCount());
    //double run_time = (end - start) / getTickFrequency();
    //cout << "run_time=" << run_time << " seconds" << endl;
    //cap.release();
    return 0;

}

