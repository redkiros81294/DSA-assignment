#include <iostream>
using namespace std;

int adition(int arr1[], int size1) {
    int sum1 = 0;
    for (int i = 0; i < size1; ++i) {
        sum1 += arr1[i];
    }
    return sum1;
}
void rotation(int arr2[], int size2, int positions) {
    int temp[size2];

    for (int i = 0; i < size2; ++i) {
        temp[(i + positions) % size2] = arr2[i];
    }

    for (int i = 0; i < size2; ++i) {
        arr2[i] = temp[i];
    }
}
int factorialofanum(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}
bool checkprime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int Maximum(int arr3[], int size3) {
    int maxElement = arr3[0];
    for (int i = 1; i < size3; ++i) {
        if (arr3[i] > maxElement) {
            maxElement = arr3[i];
        }
    }
    return maxElement;
}

// 1. 

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int totalSum = addition(arr1, size1);
    cout << "Sum of array elements: " << totalSum << endl;


// 2. 

    int arr2[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int positions = 2;

    rotation(arr2, size2, positions);

    cout << "Rotated array: ";
    for (int i = 0; i < size2; ++i) {
        cout << arr2[i] << " ";
    }
    cout <<endl;


//3. 

    int num = 5;
    int result = factorialofanum(num);
    cout << "Factorial of " << num << " is " << result << endl;


//4.

    int numb = 13;
    if (checkPrime(numb)) {
        cout << numb << " is a prime number." <<endl;
    } else {
        cout << numb << " is not a prime number." << endl;
    }



//6. 

    int arr3[] = {3, 7, 1, 9, 4};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    int maxElement = Maximum(arr3, size3);
    cout << "Maximum element: " << maxElement << endl;

    return 0;
}

//The time complexity of this solution is O(n), where n is the number of elements in the array.

