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
		/* Ĭ���������� */
		virtual ~VisionFaceTrack() {}

		/* ��ʼ������������ļ�param_path����Ҫʹ�õ�GPU���device_id */
		virtual bool Init(std::string param_path = "models_v2/face_track.json", int device_id = 0) = 0;

		/* ������Ƶ����img�����ش�ʱ��ʧ�ĸ��ٶ��� */
		virtual std::vector<VisionFace> Track(const cv::Mat& img) = 0;

		/* ��ȡ��ǰ�����и�����Ϣ */
		virtual std::vector<VisionFace> GetTrackInfo() = 0;

		/* �߼��ӿ� */
		virtual void SetRedetectInterval(int interval = 10) = 0;
		virtual void SetDetectionNonoverlapIou(float iou = 0.5f) = 0;
		virtual void SetFaceVerifyCalScoreThd(float thd = 0.5f) = 0;
		virtual void SetFaceQualityThd(float thd = 0.75f) = 0;
		virtual void SetRefindThd(float thd = 0.55f) = 0;
	};

	/* ������� */
	VISION_API VisionFaceTrack* instantiateVisionFaceTrack(int device_id = 0);

	/* ���ٶ��� */
	VISION_API void destroyVisionFaceTrack(VisionFaceTrack* ptr);
}
#endif //VISION_FACE_TRACK_H
