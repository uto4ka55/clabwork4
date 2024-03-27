#include <iostream>
using namespace std;

bool setArray(int* &arr, int& size) {
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 2) {
        cout << "The size of the array must be greater than 2." << endl;
        arr = nullptr;
        return false;
    }

    arr = new int[size];

    for (int i = 0; i < size; ++i) {
        cout << "\nEnter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    //for (int i = 0; i < size; ++i) {
        //cout << arr[i] << " ";}
    return true;
}

// Function to find the maximum of local minima and minimum of local maxima
void findMinMax(int* arr, int size, int& maxOfMin, int& minOfMax) {

    // Check for the first element as the local minimum or maximum
    if (arr[0] < arr[1]){
        maxOfMin = arr[0];
    }
    else {
        maxOfMin = arr[1];
    }
    if (arr[0] > arr[1]) {
        minOfMax = arr[0];
    }
    else {
        minOfMax = arr[1];
    }

    for (int i = 1; i < size - 1; ++i) {
        // Check for max local minimum
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {//middle number min
            if (arr[i] > maxOfMin) {
                maxOfMin = arr[i];
            }
        }

        else if (arr[i-1] < arr[i] && arr[i-1] < arr[i + 1]) {//left number min
            if (arr[i-1] > maxOfMin) {
                maxOfMin = arr[i-1];
            }
        }

        else {
            if (arr[i+1] < minOfMax) {//right number min
                minOfMax = arr[i+1];
            }
        }


        // Check for min local max
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {//middle number min
            if (arr[i] > minOfMax) {
                minOfMax = arr[i];
            }
        }

        else if (arr[i-1] > arr[i] && arr[i-1] > arr[i + 1]) {//left number min
            if (arr[i-1] > minOfMax) {
                minOfMax = arr[i-1];
            }
        }

        else {
            if (arr[i+1] < minOfMax) {//right number min
                minOfMax = arr[i+1];
            }
        }
    }

    // Check for the last element to the local minimum or maximum
    if (size > 1 && arr[size - 1] < arr[size - 2]) {
        if (arr[size - 1] > maxOfMin) {
            maxOfMin = arr[size - 1];
        }
    }
    else {
        if (arr[size - 2] > maxOfMin) {
            maxOfMin = arr[size - 2];
        }
    }
    if (size > 1 && arr[size - 1] > arr[size - 2]) {
        if (arr[size - 1] < minOfMax) {
            minOfMax = arr[size - 1];
        }
    }
    else {
        if (arr[size - 2] < minOfMax) {
            cout << "lmax = " << arr[size - 2] << endl;
            minOfMax = arr[size - 2];
        }
    }
}

// Function to output the result
void outputResult(int maxOfMin, int minOfMax) {
    cout << "Maximum of local minima: " << maxOfMin << endl;
    cout << "Minimum of local maxima: " << minOfMax << endl;
}

int main() {
    char choice;
    do {
        int* arr = nullptr;
        int size;
        int maxOfMin, minOfMax;

        if (!setArray(arr, size)) {
            choice = 'y';
            continue;
        }

        findMinMax(arr, size, maxOfMin, minOfMax);
        outputResult(maxOfMin, minOfMax);

        delete[] arr; // Free allocated memory

        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}