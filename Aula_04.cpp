#include <iostream>
#include <fstream>
#include <memory>  // For std::unique_ptr

int main() {
    const char* inputPath = "./images/Imagem.ppm";
    const char* outputPath = "./images/NovaImagem.ppm";

    //Open source file in binary
    std::ifstream image(inputPath, std::ios::binary);
   /*  if (!image) {
        std::cerr << "Error: Unable to open source file: " << inputPath << '\n';
        return 1;
    } */

    //Open destination file in binary
    std::ofstream newImage(outputPath, std::ios::binary);
   /*  if (!newImage) {
        std::cerr << "Error: Unable to create destination file: " << outputPath << '\n';
        return 1;
    } */

    //Determine file size
    image.seekg(0, std::ios::end);
    std::streamsize size = image.tellg();
    image.seekg(0, std::ios::beg);

    /* if (size <= 0) {
        std::cerr << "Error: Invalid file size.\n";
        return 1;
    } */

    //Allocate memory buffer
    std::unique_ptr<char[]> buffer(new(std::nothrow) char[size]);
  /*   if (!buffer) {
        std::cerr << "Error: Memory allocation failed.\n";
        return 1;
    } */

    //Read all data into buffer
  /*   if (!image.read(buffer.get(), size)) {
        std::cerr << "Error: Failed to read source file.\n";
        return 1;
    }
 */
    //Write buffer to output
    newImage.write(buffer.get(), size);
  /*   if (!newImage) {
        std::cerr << "Error: Failed to write to destination file.\n";
        return 1;
    } */

    std::cout << "Image copied successfully.\n";
    return 0;
}