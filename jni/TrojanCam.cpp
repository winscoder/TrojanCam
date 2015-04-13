#include <jni.h>
#include <vector>
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>


#include "org_trojancam_TrojanCam.h"

#if defined(WAIT_FOR_DEBUGGER)

void waitForDebugger()
{
	static volatile int debug = 1;
	while( debug )
	{}
}

#else

void waitForDebugger() {}

#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     org_trojancam_TrojanCam
 * Method:    orbfeature
 * Signature: (J)V
 */
JNIEXPORT jint JNICALL Java_org_trojancam_TrojanCam_orbfeature
  (JNIEnv *jni, jobject thiz, jlong addrRgba) {
	cv::Mat& mRgba  = *(cv::Mat*)addrRgba;

    	cv::ORB orb(500, 1.2f, 8, 31, 0, 2, cv::ORB::HARRIS_SCORE, 31);
	std::vector<cv::KeyPoint> keypoints;
	orb.operator ()(mRgba,cv::Mat(), keypoints, cv::noArray(), false);

	std::vector<cv::Point2f> points;
	cv::KeyPoint::convert(keypoints, points, std::vector<int>());
	if(!points.empty()) {
	    for(int i=0; i<points.size(); i++) {
	        cv::circle(mRgba, points[i], 5, cv::Scalar(0, 255, 0), 1, 8, 0);
	    }
	}
}

#ifdef __cplusplus
}
#endif
