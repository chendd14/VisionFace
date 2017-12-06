#ifndef VISION_FACE_DETECT_H
#define VISION_FACE_DETECT_H

#if defined (_MSC_VER) || defined (_WIN32) || defined (_WIN64)
#ifdef VISIONFACEDETECT_EXPORTS
#define  VISION_API __declspec(dllexport)
#else
#define  VISION_API __declspec(dllimport)
#endif // VISION_API
#else // defined (windows)
#define VISION_API
#endif

#include "VisionCommon.h"

namespace vision {
	class VISION_API VisionFaceDetect
	{
	public:
		/* 默认析构函数 */
		virtual ~VisionFaceDetect() {}

		/* 初始化，输入参数文件param_path和所要使用的GPU编号device_id */
		virtual bool Init(std::string param_path = "models_v2/face_detect_cascade.json", int device_id = 0) = 0;

		/* 输入一张图像img，获取人脸信息（包括人脸框和关键点）；在输入视频的情况下，将is_video_stream设置为true，能够极大提升检测速度 */
		virtual std::vector<VisionFace> GetFaces(const cv::Mat& img, bool is_video_stream = false) = 0;

		/* 输入一张图像img，返回所有的人脸框以及对应的人脸关键点（引用形式返回） */
		virtual std::vector<cv::Rect> GetFaces(const cv::Mat& img, std::vector<std::vector<cv::Point2f>>& key_pts, bool is_video_stream = false) = 0;

		/* 获取图像img中最大人脸的人脸框 */
		virtual std::vector<VisionFace> GetMaximumFace(const cv::Mat& img, bool is_video_stream = false) = 0;

		/* 将人脸框face_rect绘制在图像img上 */
		virtual void DrawFaceRect(cv::Mat& img, cv::Rect face_rect) = 0;

		/* 以下接口为高级接口，一般情况下不需要使用 */
		virtual void SetRedetectInterval(int interval = 8) = 0;
		virtual void SetMinFaceSize(int size = 35) = 0;
		virtual void SetScaleFactor(float factor = 0.71f) = 0;
		virtual void SetMaxWidthGlobal(int size = 640) = 0;
		virtual void SetDetectThd(float thd1 = 0.75f, float thd2 = 0.85f, float thd3 = 0.90f) = 0;
		virtual void SetStepSize(int size = 4) = 0;
	};

	/* 构造对象，默认使用GPU 0 */
	VISION_API VisionFaceDetect* instantiateVisionFaceDetect(int device_id = 0);

	/* 销毁对象 */
	VISION_API void destroyVisionFaceDetect(VisionFaceDetect* ptr);
}
#endif // VISION_FACE_DETECT_H
