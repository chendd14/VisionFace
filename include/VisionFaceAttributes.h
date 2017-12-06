#ifndef VISION_FACE_ATTRIBUTES_H
#define VISION_FACE_ATTRIBUTES_H

#include "VisionCommon.h"

#if defined (_MSC_VER) || defined (_WIN32) || defined (_WIN64)
#ifdef VISIONFACEATTRIBUTES_EXPORTS
#define  VISION_API __declspec(dllexport)
#else
#define  VISION_API __declspec(dllimport)
#endif // VISION_API
#else // defined (windows)
#define VISION_API
#endif

namespace vision {
	class VISION_API VisionFaceAttributes
	{
	public:
		/* 默认析构函数 */
		virtual ~VisionFaceAttributes() {}

		/* 初始化，输入参数文件param_path和所要使用的GPU编号device_id */
		virtual bool Init(std::string param_path = "models_v2/face_attributes.json", int device_id = 0) = 0;

		/* 输入一张归一化人脸图像，输出人脸属性 */
		virtual std::vector<int> GetAttribtues(const cv::Mat& img, std::vector<float>& feature = std::vector<float>()) = 0;

		/* 批量获取人脸属性 */
		virtual std::vector<std::vector<int> > GetAttribtues(const std::vector<cv::Mat>& imgs, std::vector<std::vector<float>>& feature = std::vector<std::vector<float>>()) = 0;
	};

	/* 构造此类的一个对象， 默认使用GPU 0 */
	VISION_API VisionFaceAttributes* instantiateVisionFaceAttributes(int device_id = 0);

	/* 销毁此类的一个对象 */
	VISION_API void destroyVisionFaceAttributes(VisionFaceAttributes* ptr);
}
#endif // VISION_FACE_ATTRIBUTES_H
