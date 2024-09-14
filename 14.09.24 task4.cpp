#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;
//hrl

int findMax(int* arr, int size) {
    if (size <= 0) {
        throw invalid_argument("Array size must be greater than 0");
    }

    int maxElement = arr[0]; 

    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i]; 
        }
    }

    return maxElement;
}


int findMin(int* arr, int size) {
    if (size <= 0) {
        throw invalid_argument("Array size must be greater than 0");
    }

    int minElement = arr[0]; 

    for (int i = 1; i < size; ++i) {
        if (arr[i] < minElement) {
            minElement = arr[i]; 
        }
    }

    return minElement;
}


double findAverage(int* arr, int size) {
    if (size <= 0) {
        throw invalid_argument("Array size must be greater than 0");
    }

    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    return sum / size; 
}


void fillArrayWithRandomNumbers(int* arr, int size, int minVal, int maxVal) {
    for (int i = 0; i < size; ++i) {
        arr[i] = minVal + (rand() % (maxVal - minVal + 1)); 
    }
}

int main() {
    const int MIN_VAL = 1;
    const int MAX_VAL = 10;
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) {
        cerr << "Array size must be greater than 0." << endl;
        return EXIT_FAILURE;
    }

    int* arr = new int[size];


    srand(static_cast<unsigned>(time(0)));


    fillArrayWithRandomNumbers(arr, size, MIN_VAL, MAX_VAL);

    cout << "Array contents: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;


    int choice;
    cout << "Choose an option:" << endl;
    cout << "1 - Find Max" << endl;
    cout << "2 - Find Min" << endl;
    cout << "3 - Find Average" << endl;
    cin >> choice;

    // Вказівники на функції
    int (*funcInt)(int*, int) = nullptr;
    double (*funcDouble)(int*, int) = nullptr;

    switch (choice) {
    case 1:
        funcInt = findMax;
        if (funcInt != nullptr) {
            cout << "Max value: " << funcInt(arr, size) << endl;
        }
        break;
    case 2:
        funcInt = findMin;
        if (funcInt != nullptr) {
            cout << "Min value: " << funcInt(arr, size) << endl;
        }
        break;
    case 3:
        funcDouble = findAverage;
        if (funcDouble != nullptr) {
            cout << "Average value: " << funcDouble(arr, size) << endl;
        }
        break;
    default:
        cerr << "Invalid choice." << endl;
        delete[] arr;
        return EXIT_FAILURE;
    }

    delete[] arr; 
    return EXIT_SUCCESS;
}
