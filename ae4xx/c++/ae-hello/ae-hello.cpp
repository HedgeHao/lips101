#include <iostream>
#include <librealsense2/rs.hpp>

int main()
{
    rs2::pipeline p;
    p.start();

    // Wait Until frames are available
    rs2::frameset frameset = p.wait_for_frames();

    // Get a depth frame image.
    rs2::depth_frame frame = frameset.get_depth_frame();

    // Get frame size.
    float width = frame.get_width();
    float height = frame.get_height();

    // Get distance from the camera to the center of this frame
    float dist_to_center = frame.get_distance((int)(width / 2), (int)(height / 2));

    printf("Distance (%d, %d): %.3f meters\n", (int)(width / 2), (int)(height / 2), dist_to_center);

    return 0;
}