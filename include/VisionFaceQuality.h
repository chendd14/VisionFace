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
		/* 默认析构函数 */
		virtual ~VisionFaceQuality() {}

		/* 初始化，输入参数文件param_path和所要使用的GPU编号device_id */
		virtual bool Init(std::string param_path = "models_v2/face_quality.json", int device_id = 0) = 0;

		/* 输入一张归一化人脸图像，输出人脸质量得分[0,1]，分数越高说明质量越好 */
		virtual float GetFaceQuality(const cv::Mat& img) = 0;

		/* 批量获取人脸图像质量 */
		virtual std::vector<float> GetFaceQuality(const std::vector<cv::Mat>& imgs) = 0;
	};

	/* 构造对象，默认使用GPU 0 */
	VISION_API VisionFaceQuality* instantiateVisionFaceQuality(int device_id = 0);

	/* 销毁对象 */
	VISION_API void destroyVisionFaceQuality(VisionFaceQuality* ptr);
}
#endif // _VISION_FACE_QUALITY_H
