#ifndef VISION_FACE_TRACK_H
#define VISION_FACE_TRACK_H

#include "VisionCommon.h"

#if defined (_MSC_VER) || defined (_WIN32) || defined (_WIN64)
#ifdef VISIONFACETRACK_EXPORTS
#define  VISION_API __declspec(dllexport)
#else
#define  VISION_API __declspec(dllimport)
#endif // VISION_API
#else // defined (windows)
#define VISION_API
#endif

namespace vision {
	class VISION_API VisionFaceTrack
	{
	public:
		/* 默认析构函数 */
		virtual ~VisionFaceTrack() {}

		/* 初始化，输入参数文件param_path和所要使用的GPU编号device_id */
		virtual bool Init(std::string param_path = "models_v2/face_track.json", int device_id = 0) = 0;

		/* 输入视频序列img，返回此时丢失的跟踪对象 */
		virtual std::vector<VisionFace> Track(const cv::Mat& img) = 0;

		/* 获取当前的所有跟踪信息 */
		virtual std::vector<VisionFace> GetTrackInfo() = 0;

		/* 高级接口 */
		virtual void SetRedetectInterval(int interval = 10) = 0;
		virtual void SetDetectionNonoverlapIou(float iou = 0.5f) = 0;
		virtual void SetFaceVerifyCalScoreThd(float thd = 0.5f) = 0;
		virtual void SetFaceQualityThd(float thd = 0.75f) = 0;
		virtual void SetRefindThd(float thd = 0.55f) = 0;
	};

	/* 构造对象 */
	VISION_API VisionFaceTrack* instantiateVisionFaceTrack(int device_id = 0);

	/* 销毁对象 */
	VISION_API void destroyVisionFaceTrack(VisionFaceTrack* ptr);
}
#endif //VISION_FACE_TRACK_H
