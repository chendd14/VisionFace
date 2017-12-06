#ifndef VISION_FACE_FEATURE_H
#define VISION_FACE_FEATURE_H

#include "VisionCommon.h"

#if defined (_MSC_VER) || defined (_WIN32) || defined (_WIN64)
#ifdef VISIONFACEFEATURE_EXPORTS
#define  VISION_API __declspec(dllexport)
#else
#define  VISION_API __declspec(dllimport)
#endif // VISION_API
#else // defined (windows)
#define VISION_API
#endif

namespace vision {
	class VISION_API VisionFaceFeature
	{
	public:
		/* Ĭ���������� */
		virtual ~VisionFaceFeature() {}

		/* ��ʼ������������ļ�param_path����Ҫʹ�õ�GPU���device_id */
		virtual bool Init(std::string param_path = "models_v2/face_feature.json", int device_id = 0) = 0;

		/* ��ȡ�����һ������ͼ��img������ */
		virtual std::vector<float> GetFeature(const cv::Mat& img) = 0;

		/* ������ȡ��һ������ͼ������ */
		virtual std::vector<std::vector<float>> GetFeature(const std::vector<cv::Mat>& imgs) = 0;

		/* ��ȡ�����������������ƶ� */
		virtual float GetScore(const std::vector<float>& fea1, const std::vector<float>& fea2) = 0;
	};

	/* ������� Ĭ��ʹ��GPU 0 */
	VISION_API VisionFaceFeature* instantiateVisionFaceFeature(int device_id = 0);

	/* ���ٶ��� */
	VISION_API void destroyVisionFaceFeature(VisionFaceFeature* ptr);
}
#endif // VISION_FACE_FEATURE_H
