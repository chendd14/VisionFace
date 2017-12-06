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
		/* Ĭ���������� */
		virtual ~VisionFaceAttributes() {}

		/* ��ʼ������������ļ�param_path����Ҫʹ�õ�GPU���device_id */
		virtual bool Init(std::string param_path = "models_v2/face_attributes.json", int device_id = 0) = 0;

		/* ����һ�Ź�һ������ͼ������������� */
		virtual std::vector<int> GetAttribtues(const cv::Mat& img, std::vector<float>& feature = std::vector<float>()) = 0;

		/* ������ȡ�������� */
		virtual std::vector<std::vector<int> > GetAttribtues(const std::vector<cv::Mat>& imgs, std::vector<std::vector<float>>& feature = std::vector<std::vector<float>>()) = 0;
	};

	/* ��������һ������ Ĭ��ʹ��GPU 0 */
	VISION_API VisionFaceAttributes* instantiateVisionFaceAttributes(int device_id = 0);

	/* ���ٴ����һ������ */
	VISION_API void destroyVisionFaceAttributes(VisionFaceAttributes* ptr);
}
#endif // VISION_FACE_ATTRIBUTES_H
