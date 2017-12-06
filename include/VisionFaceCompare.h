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
		/* 默认构造函数 */
		virtual ~VisionFaceCompare() {}

		/* 初始化模块，构建Database，输入特征维数feature_dim和特征的个数number（可以更改） */
		virtual bool Init(int feature_dim, int number) = 0;

		/* 重新调整需要存储的特征的个数，并且选择是否保留已有的数据 */
		virtual void ReSize(int number, bool reserve_data = true) = 0;

		/* 清除Database中的数据 */
		virtual void Clear() = 0;

		/* 将特征添加到Database */
		virtual bool Add(const std::vector<float>& feature) = 0;

		/* 获取比对相似度Top N的比对结果 */
		virtual std::vector<VisionFaceCompareResult> GetResult(const std::vector<float>& feature, int top_k = 10) = 0;

		/* 获取两张图片之间的相似度 */
		virtual float GetScore(const std::vector<float>& fea1, const std::vector<float>& fea2) = 0;
	};

	/* 构造对象 */
	VISION_API VisionFaceCompare* instantiateVisionFaceCompare();

	/* 销毁对象 */
	VISION_API void destroyVisionFaceCompare(VisionFaceCompare* _ptr);
}
#endif //VISION_FACE_COMPARE_H
