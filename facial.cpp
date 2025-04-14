#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <vector>
using namespace cv;
using namespace std;

class Face {

private:

    VideoCapture camera;
    Mat image;
    Mat gray;
    CascadeClassifier cascade;
    vector<Rect> faces; // vector to store rectangles

public:

    Face() : camera(0) {

        cascade.load("haarcascade_frontalface_default.xml");

        if (cascade.empty()) {
            cout << "XML file is empty";
        }

        if (!camera.isOpened()) {
            cout << "could not open the camera";
        }

        while (true) {

            int faces_counter = 0;

            camera.read(image);
            flip(image, image, 1); // to turn the camera side
            cascade.detectMultiScale(image, faces, 1.1, 3); // standard example to detect multiple scales

            for (int i = 0; i < faces.size(); i++) {

                rectangle(image, faces[i].tl(), faces[i].br(), Scalar(255, 0, 0));

                // tl() -> top-left corner coordinates
                // br() -> bottom-right corner coordinates
                // Scalar(255,0,0) -> blue color

                faces_counter++;
            }

            putText(image, "Faces: " + to_string(faces_counter), Point(40, 40), FONT_HERSHEY_SIMPLEX,1, (255,0,0), 2);
            // 1. image to draw the text | 2. text | 3. bottom-left corner |
            // 4. font to use | 5. font scale | 6. color | 7. line thickness 

            namedWindow("frame", WINDOW_AUTOSIZE);
            imshow("frame", image);
            waitKey(1);
         
        }
    }
};

int main() {
    Face face;
    return 0;
}
