#include <iostream>
#include <string>

class Image {
private:
    std::string filename;     // Denumirea fișierului
    std::string compression;  // Formatul de compresie
    int width;                // Lățimea imaginii în pixeli
    int height;               // Înălțimea imaginii în pixeli
    int sizeInBytes;          // Dimensiunea imaginii în octeți
    float compressionPercentage;  // Compresia în %

public:
    // Constructor cu parametri pentru inițializarea completă
    Image(std::string filename, std::string compression, int width, int height, int sizeInBytes, float compressionPercentage) 
        : filename(filename), compression(compression), width(width), height(height), sizeInBytes(sizeInBytes), compressionPercentage(compressionPercentage) {}

    // Constructor cu parametru pentru schimbarea denumirii fișierului
    Image(std::string newFilename) : filename(newFilename), compression(""), width(0), height(0), sizeInBytes(0), compressionPercentage(0.0) {}

    // Funcții pentru modificarea datelor
    void setFilename(std::string newFilename) {
        filename = newFilename;
    }

    void setCompression(std::string newCompression) {
        compression = newCompression;
    }

    void setDimensions(int newWidth, int newHeight) {
        width = newWidth;
        height = newHeight;
    }

    void setSizeInBytes(int newSizeInBytes) {
        sizeInBytes = newSizeInBytes;
    }

    void setCompressionPercentage(float newCompressionPercentage) {
        compressionPercentage = newCompressionPercentage;
    }

    // Funcție pentru afișarea informațiilor despre imagine
    void displayInfo() {
        std::cout << "Filename: " << filename << "\n";
        std::cout << "Compression: " << compression << "\n";
        std::cout << "Dimensions: " << width << "x" << height << " pixels\n";
        std::cout << "Size in bytes: " << sizeInBytes << " bytes\n";
        std::cout << "Compression percentage: " << compressionPercentage << " %\n";
    }
};

int main() {
    // Exemplu de utilizare
    Image image1("image1.jpg", "JPEG", 1920, 1080, 1536000, 80.0);
    image1.displayInfo();

    // Modificare denumire fișier
    image1.setFilename("new_image1.jpg");
    image1.displayInfo();

    return 0;
}