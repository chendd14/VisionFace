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
		/* 默认析构函数 */
		virtual ~VisionFaceFeature() {}

		/* 初始化，输入参数文件param_path和所要使用的GPU编号device_id */
		virtual bool Init(std::string param_path = "models_v2/face_feature.json", int device_id = 0) = 0;

		/* 获取输入归一化人脸图像img的特征 */
		virtual std::vector<float> GetFeature(const cv::Mat& img) = 0;

		/* 批量获取归一化人脸图像特征 */
		virtual std::vector<std::vector<float>> GetFeature(const std::vector<cv::Mat>& imgs) = 0;

		/* 获取两张人脸特征的相似度 */
		virtual float GetScore(const std::vector<float>& fea1, const std::vector<float>& fea2) = 0;
	};

	/* 构造对象， 默认使用GPU 0 */
	VISION_API VisionFaceFeature* instantiateVisionFaceFeature(int device_id = 0);

	/* 销毁对象 */
	VISION_API void destroyVisionFaceFeature(VisionFaceFeature* ptr);
}
#endif // VISION_FACE_FEATURE_H
