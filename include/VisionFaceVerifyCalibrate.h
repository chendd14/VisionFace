#ifndef VISION_FACE_VERIFYCALIBRATE_H
#define VISION_FACE_VERIFYCALIBRATE_H

#if defined (_MSC_VER) || defined (_WIN32) || defined (_WIN64)
#ifdef VISIONFACEVERIFYCALIBRATE_EXPORTS
#define  VISION_API __declspec(dllexport)
#else
#define  VISION_API __declspec(dllimport)
#endif // VISION_API
#else // defined (windows)
#define VISION_API
#endif

#define __T

#include "VisionCommon.h"

namespace vision {
	class VISION_API VisionFaceVerifyCalibrate
	{
	public:
		/* Ĭ���������� */
		virtual ~VisionFaceVerifyCalibrate() {}

		/* ��ʼ������������ļ�param_path����Ҫʹ�õ�GPU���device_id */
		virtual bool Init(std::string param_path = "models_v2/face_verifycalibrate.json", int device_id = 0) = 0;

		/* ����ͼ��img��������face_rect����������������ŶȺ��µ����������÷��أ� */
		virtual float VerifyCalibrate(const cv::Mat& img, cv::Rect& face_rect) = 0;

		/* �������� */
		virtual std::vector<float> VerifyCalibrate(const cv::Mat& img, std::vector<cv::Rect>& face_rects) = 0;
#ifdef __T
		/* ����������ͬʱ���������ؼ������ڵ�λ�ã����÷��أ� */
		virtual std::vector<float> VerifyCalibrateT(const cv::Mat& img, std::vector<cv::Rect>& face_rects, std::vector<std::vector<cv::Point2f>>& key_pts) = 0;
#endif
	};

	/* ������� */
	VISION_API VisionFaceVerifyCalibrate* instantiateVisionFaceVerifyCalibrate(int device_id = 0);

	/* ���ٶ��� */
	VISION_API void destroyVisionFaceVerifyCalibrate(VisionFaceVerifyCalibrate* ptr);
}
#endif // VISION_FACE_VERIFYCALIBRATE_H
