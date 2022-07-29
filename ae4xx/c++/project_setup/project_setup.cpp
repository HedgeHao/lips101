#include <librealsense2/rs.hpp>
#include <opencv2/core/core.hpp>

int main()
{
    printf("Realsense Version:%s\n", RS2_API_FULL_VERSION_STR);

    printf("OpenCV Version:%s\n", CV_VERSION);
    return 0;
}