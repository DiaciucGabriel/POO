#include <iostream>
#include <cmath>

struct Vector {
    float* data;
    int size;
};


void initVector(Vector& vec, int size) {
    vec.data = new float[size];
    vec.size = size;
}


void deleteVector(Vector& vec) {
    delete[] vec.data;
    vec.size = 0;
}


void resizeVector(Vector& vec, int newSize) {
    if (vec.size != newSize) {
        float* newData = new float[newSize];
        int minSize = std::min(vec.size, newSize);
        for (int i = 0; i < minSize; i++) {
            newData[i] = vec.data[i];
        }
        delete[] vec.data;
        vec.data = newData;
        vec.size = newSize;
    }
}


float& getElement(Vector& vec, int index) {
    if (index >= 0 && index < vec.size) {
        return vec.data[index];
    } else {
        throw std::out_of_range("Index out of range");
    }
}


float norm(Vector& vec) {
    float result = 0.0f;
    for (int i = 0; i < vec.size; i++) {
        result += vec.data[i] * vec.data[i];
    }
    return std::sqrt(result);
}

int main() {
    Vector myVector;
    initVector(myVector, 5);

    
    for (int i = 0; i < myVector.size; i++) {
        myVector.data[i] = i + 1.0f;
    }

    
    float numToAdd = 2.5f;
    for (int i = 0; i < myVector.size; i++) {
        myVector.data[i] += numToAdd;
    }

    
    std::cout << "Vector: ";
    for (int i = 0; i < myVector.size; i++) {
        std::cout << myVector.data[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Norma vectorului: " << norm(myVector) << std::endl;

    
    deleteVector(myVector);

    return 0;
}
