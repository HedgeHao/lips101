#include <librealsense2/rs.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main()
{
    rs2::pipeline p;
    p.start();

    while (cv::waitKey(1) != 'q')
    {
        rs2::frameset frameset = p.wait_for_frames();
        rs2::depth_frame frame = frameset.get_depth_frame();
        rs2::video_frame colorFrame = frameset.get_color_frame();

        float width = frame.get_width();
        float height = frame.get_height();
        float dist_to_center = frame.get_distance((int)(width / 2), (int)(height / 2));

        cv::Mat image(
            cv::Size(width, height),
            CV_8UC3,
            (void *)colorFrame.get_data(),
            cv::Mat::AUTO_STEP);

        cv::cvtColor(image, image, cv::COLOR_RGB2BGR);

        cv::line(image, cv::Point((width / 2) - 15, (height / 2)),
                 cv::Point((width / 2) + 15, (height / 2)),
                 cv::Scalar(0, 0, 255),
                 2, cv::LINE_8);
        cv::line(image, cv::Point((width / 2), (height / 2) - 15),
                 cv::Point((width / 2), (height / 2) + 15),
                 cv::Scalar(0, 0, 255),
                 2, cv::LINE_8);

        cv::putText(image, std::to_string(dist_to_center), cv::Point(0, height), 2, 2, cv::Scalar(0, 0, 255));

        cv::imshow("Preview", image);
    }

    p.stop();

    return 0;
}