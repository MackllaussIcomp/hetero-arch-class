#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    const int width = 50;
    const int height = 70;
    const int halfHeight = height / 2;

    std::ofstream image_Input("./images/Imagem.ppm");

    if (!image_Input.is_open()) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    // Write PPM header
    image_Input << "P3\n" << width << " " << height << "\n255\n";

    // Build a green row: 0 255 0
    std::ostringstream greenLine;
    for (int i = 0; i < width; ++i)
        greenLine << "0 255 0 ";
    std::string greenRow = greenLine.str();

    // Build a blue row: 0 0 255
    std::ostringstream blueLine;
    for (int i = 0; i < width; ++i)
        blueLine << "0 0 255 ";
    std::string blueRow = blueLine.str();

    // Write top half: green
    for (int y = 0; y < halfHeight; ++y)
        image_Input << greenRow << "\n";

    // Write bottom half: blue
    for (int y = halfHeight; y < height; ++y)
        image_Input << blueRow << "\n";

    image_Input.close();
    return 0;
}
