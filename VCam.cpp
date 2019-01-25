// OpenCVWebcamTest.cpp

#include "pch.h"
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>


#include<iostream>
#include<conio.h>           // may have to modify this line if not using Windows

///////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
	cv::VideoCapture capWebcam(0);            // declare a VideoCapture object and associate to webcam, 0 => use 1st webcam

	if (capWebcam.isOpened() == false) {                                // check if VideoCapture object was associated to webcam successfully
		std::cout << "error: capWebcam not accessed successfully\n\n";      // if not, print error message to std out
		_getch();                                                           // may have to modify this line if not using Windows
		return(0);                                                          // and exit program
	}

	cv::Mat imgOriginal;        // input image

	char charCheckForEscKey = 0;

	while (charCheckForEscKey != 27 && capWebcam.isOpened()) {            // until the Esc key is pressed or webcam connection is lost
		bool blnFrameReadSuccessfully = capWebcam.read(imgOriginal);            // get next frame

		if (!blnFrameReadSuccessfully || imgOriginal.empty()) {                 // if frame not read successfully
			std::cout << "error: frame not read from webcam\n";                 // print error message to std out
			break;                                                              // and jump out of while loop
		}
               // convert to grayscale
		cv::flip(imgOriginal, imgOriginal, 1);
								  // declare windows
		cv::namedWindow("imgOriginal", 1);       // note: you can use CV_WINDOW_NORMAL which allows resizing the window
																// CV_WINDOW_AUTOSIZE is the default
		cv::imshow("imgOriginal", imgOriginal);                 // show windows

		charCheckForEscKey = cv::waitKey(1);        // delay (in ms) and get key press, if any
	}   // end while

	return(0);
}









