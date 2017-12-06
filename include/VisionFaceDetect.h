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
		/* Ĭ���������� */
		virtual ~VisionFaceDetect() {}

		/* ��ʼ������������ļ�param_path����Ҫʹ�õ�GPU���device_id */
		virtual bool Init(std::string param_path = "models_v2/face_detect_cascade.json", int device_id = 0) = 0;

		/* ����һ��ͼ��img����ȡ������Ϣ������������͹ؼ��㣩����������Ƶ������£���is_video_stream����Ϊtrue���ܹ�������������ٶ� */
		virtual std::vector<VisionFace> GetFaces(const cv::Mat& img, bool is_video_stream = false) = 0;

		/* ����һ��ͼ��img���������е��������Լ���Ӧ�������ؼ��㣨������ʽ���أ� */
		virtual std::vector<cv::Rect> GetFaces(const cv::Mat& img, std::vector<std::vector<cv::Point2f>>& key_pts, bool is_video_stream = false) = 0;

		/* ��ȡͼ��img����������������� */
		virtual std::vector<VisionFace> GetMaximumFace(const cv::Mat& img, bool is_video_stream = false) = 0;

		/* ��������face_rect������ͼ��img�� */
		virtual void DrawFaceRect(cv::Mat& img, cv::Rect face_rect) = 0;

		/* ���½ӿ�Ϊ�߼��ӿڣ�һ������²���Ҫʹ�� */
		virtual void SetRedetectInterval(int interval = 8) = 0;
		virtual void SetMinFaceSize(int size = 35) = 0;
		virtual void SetScaleFactor(float factor = 0.71f) = 0;
		virtual void SetMaxWidthGlobal(int size = 640) = 0;
		virtual void SetDetectThd(float thd1 = 0.75f, float thd2 = 0.85f, float thd3 = 0.90f) = 0;
		virtual void SetStepSize(int size = 4) = 0;
	};

	/* �������Ĭ��ʹ��GPU 0 */
	VISION_API VisionFaceDetect* instantiateVisionFaceDetect(int device_id = 0);

	/* ���ٶ��� */
	VISION_API void destroyVisionFaceDetect(VisionFaceDetect* ptr);
}
#endif // VISION_FACE_DETECT_H
