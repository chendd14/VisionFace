#ifndef _VISION_COMMON_H
#define _VISION_COMMON_H

#include "opencv2/opencv.hpp"

namespace vision {
	struct VisionFace
	{
		int face_id;
		cv::Rect bbox;
		std::vector<cv::Point2f> key_pts;
		cv::Mat norm_face;
		cv::Mat face4show;
		float face_quality_score;
		std::vector<std::pair<cv::Mat, float>> norm_faces; // norm face & face quality score
		std::vector<cv::Mat> faces4show;
		int gender; // 0 female£»1 male
		int race;  // 0 yellow; 1 black; 2 white
		int age; // 0 children; 1 teenage; 2 adult; 3 old
		int glasses; // 0 no; 1 yes; 2 sunglasses
		int eye; // 0 open; 1 close
		int mask; // 0 no; 1 yes
		int beard; // 0 no; 1 yes
		int track_frames;
		std::vector<cv::Point2f> tracking_path; // histroy face position

		cv::Mat GetBestFace()
		{
			int idx = 0;
			float score = -1.0f;
			for (int i=0; i<norm_faces.size(); i++)
			{
				if (norm_faces.at(i).second > score)
				{
					score = norm_faces.at(i).second;
					idx = i;
				}
			}
			return norm_faces.at(idx).first;
		}

		cv::Rect GetBbox()
		{
			return bbox;
		}

		std::vector<cv::Point2f> GetKeyPts()
		{
			return key_pts;
		}
	};
}
#endif