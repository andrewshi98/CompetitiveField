#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        int* arr = new int[size];
        for (int j = 0; j < size; j++) {
            cin >> arr[j];
        }
        int op = 0;
        for (int j = 1; j < size - 1; j++) {
            if (arr[j-1] < arr[j] && arr[j] > arr[j+1]) {
                op++;
                if (j+2 < size && arr[j+2] > arr[j]) {
                    arr[j+1] = arr[j+2];
                } else {
                    arr[j+1] = arr[j];
                }
            }
        }
        cout << op << endl;
        cout << arr[0];
        for (int j = 1; j < size; j++) {
            cout << " " << arr[j];
        }
        cout << endl;
        delete[] arr;
    }
    return 0;
}