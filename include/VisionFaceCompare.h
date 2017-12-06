#ifndef VISION_FACE_COMPARE_H
#define VISION_FACE_COMPARE_H

#include "VisionCommon.h"

#if defined (_MSC_VER) || defined (_WIN32) || defined (_WIN64)
#ifdef VISIONFACECOMPARE_EXPORTS
#define  VISION_API __declspec(dllexport)
#else
#define  VISION_API __declspec(dllimport)
#endif // VISION_API
#else // defined (windows)
#define VISION_API
#endif

namespace vision {

	struct VisionFaceCompareResult
	{
		int idx;
		float score;
	};

	class VISION_API VisionFaceCompare
	{
	public:
		/* Ĭ�Ϲ��캯�� */
		virtual ~VisionFaceCompare() {}

		/* ��ʼ��ģ�飬����Database����������ά��feature_dim�������ĸ���number�����Ը��ģ� */
		virtual bool Init(int feature_dim, int number) = 0;

		/* ���µ�����Ҫ�洢�������ĸ���������ѡ���Ƿ������е����� */
		virtual void ReSize(int number, bool reserve_data = true) = 0;

		/* ���Database�е����� */
		virtual void Clear() = 0;

		/* ��������ӵ�Database */
		virtual bool Add(const std::vector<float>& feature) = 0;

		/* ��ȡ�ȶ����ƶ�Top N�ıȶԽ�� */
		virtual std::vector<VisionFaceCompareResult> GetResult(const std::vector<float>& feature, int top_k = 10) = 0;

		/* ��ȡ����ͼƬ֮������ƶ� */
		virtual float GetScore(const std::vector<float>& fea1, const std::vector<float>& fea2) = 0;
	};

	/* ������� */
	VISION_API VisionFaceCompare* instantiateVisionFaceCompare();

	/* ���ٶ��� */
	VISION_API void destroyVisionFaceCompare(VisionFaceCompare* _ptr);
}
#endif //VISION_FACE_COMPARE_H
