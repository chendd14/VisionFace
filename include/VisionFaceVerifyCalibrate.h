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
		/* 默认析构函数 */
		virtual ~VisionFaceVerifyCalibrate() {}

		/* 初始化，输入参数文件param_path和所要使用的GPU编号device_id */
		virtual bool Init(std::string param_path = "models_v2/face_verifycalibrate.json", int device_id = 0) = 0;

		/* 输入图像img和人脸框face_rect，返回人脸框的置信度和新的人脸框（引用返回） */
		virtual float VerifyCalibrate(const cv::Mat& img, cv::Rect& face_rect) = 0;

		/* 批量处理 */
		virtual std::vector<float> VerifyCalibrate(const cv::Mat& img, std::vector<cv::Rect>& face_rects) = 0;
#ifdef __T
		/* 批量处理，并同时返回人脸关键点所在的位置（引用返回） */
		virtual std::vector<float> VerifyCalibrateT(const cv::Mat& img, std::vector<cv::Rect>& face_rects, std::vector<std::vector<cv::Point2f>>& key_pts) = 0;
#endif
	};

	/* 构造对象 */
	VISION_API VisionFaceVerifyCalibrate* instantiateVisionFaceVerifyCalibrate(int device_id = 0);

	/* 销毁对象 */
	VISION_API void destroyVisionFaceVerifyCalibrate(VisionFaceVerifyCalibrate* ptr);
}
#endif // VISION_FACE_VERIFYCALIBRATE_H
