#ifndef VISION_FACE_ALIGNMENT_H
#define VISION_FACE_ALIGNMENT_H

#include "VisionCommon.h"

#if defined (_MSC_VER) || defined (_WIN32) || defined (_WIN64)
#ifdef VISIONFACEALIGNMENT_EXPORTS
#define  VISION_API __declspec(dllexport)
#else
#define  VISION_API __declspec(dllimport)
#endif // VISION_API
#else // defined (windows)
#define VISION_API
#endif

namespace vision {
	class VISION_API VisionFaceAlignment
	{
	public:
		/* Ĭ���������� */
		virtual ~VisionFaceAlignment() {}

		/* ��ʼ������������ļ�param_path����Ҫʹ�õ�GPU���device_id */
		virtual bool Init(std::string param_path = "models_v2/face_align.json", int device_id = 0) = 0;

		/* ����һ��ͼ��img��������face_rect����������Ĺؼ���λ�� */
		virtual std::vector<cv::Point2f> GetKeyPoints(const cv::Mat& img, const cv::Rect& face_rect) = 0;

		/* ������ȡ�����Ĺؼ���λ�� */
		virtual std::vector<std::vector<cv::Point2f>> GetKeyPoints(const cv::Mat& img, const std::vector<cv::Rect>& face_rects) = 0;

		/* ����һ��ͼ��img��������face_rect�����һ�Ź�һ��������180x220������padding��true������ͼ��任��ʱ������ܱߵ����ؽ��в��� */
		virtual cv::Mat GetAlignedFace(const cv::Mat& img, const cv::Rect& face_rect, bool padding = false) = 0;

		/* ������ȡ��һ������ */
		virtual std::vector<cv::Mat> GetAlignedFace(const cv::Mat& img, const std::vector<cv::Rect>& face_rect, bool padding = false) = 0;

		/* ����һ��ͼ��img�������ؼ���key_pts�����һ�Ź�һ������ */
		virtual cv::Mat GetAlignedFace(const cv::Mat& img, const std::vector<cv::Point2f>& key_pts, bool padding = false) = 0;

		/* ������ȡ��һ������ */
		virtual std::vector<cv::Mat> GetAlignedFace(const cv::Mat& img, const std::vector<std::vector<cv::Point2f>>& key_pts, bool padding = false) = 0;

		/* ���������ؼ��㣬��ȡ������̬��pitch��yaw��roll */
		virtual std::vector<float> GetHeadPose(const std::vector<cv::Point2f>& key_pts) = 0;

		/* ������ȡ������̬ */
		virtual std::vector<std::vector<float>> GetHeadPose(const std::vector<std::vector<cv::Point2f>>& key_pts) = 0;
	};

	/* ���������������device_id��Ĭ��ʹ��GPU 0 */
	VISION_API VisionFaceAlignment* instantiateVisionFaceAlignment(int device_id = 0);

	/* ���ٶ��� */
	VISION_API void destroyVisionFaceAlignment(VisionFaceAlignment* ptr);
}
#endif // VISION_FACE_ALIGNMENT_H
