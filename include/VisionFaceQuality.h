#ifndef VISION_FACE_QUALITY_H
#define VISION_FACE_QUALITY_H

#include "VisionCommon.h"

#if defined (_MSC_VER) || defined (_WIN32) || defined (_WIN64)
#ifdef VISIONFACEQUALITY_EXPORTS
#define  VISION_API __declspec(dllexport)
#else
#define  VISION_API __declspec(dllimport)
#endif // VISION_API
#else // defined (windows)
#define VISION_API
#endif

namespace vision {
	class VISION_API VisionFaceQuality
	{
	public:
		/* Ĭ���������� */
		virtual ~VisionFaceQuality() {}

		/* ��ʼ������������ļ�param_path����Ҫʹ�õ�GPU���device_id */
		virtual bool Init(std::string param_path = "models_v2/face_quality.json", int device_id = 0) = 0;

		/* ����һ�Ź�һ������ͼ��������������÷�[0,1]������Խ��˵������Խ�� */
		virtual float GetFaceQuality(const cv::Mat& img) = 0;

		/* ������ȡ����ͼ������ */
		virtual std::vector<float> GetFaceQuality(const std::vector<cv::Mat>& imgs) = 0;
	};

	/* �������Ĭ��ʹ��GPU 0 */
	VISION_API VisionFaceQuality* instantiateVisionFaceQuality(int device_id = 0);

	/* ���ٶ��� */
	VISION_API void destroyVisionFaceQuality(VisionFaceQuality* ptr);
}
#endif // _VISION_FACE_QUALITY_H
