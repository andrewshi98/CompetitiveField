#include <iostream>

using namespace std;

void sol();

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        sol();
    }
    return 0;
}

void sol() {
    int size;
    cin >> size;
    int arr[size];
    for (int j = 0; j < size; j++) {
        cin >> arr[j];
    }
    bool cheat = false;
    if (arr[size - 1] >= 0) {
        cheat = true;
    }

    if (cheat) {
        if (arr[size - 2] > arr[size - 1]) {
            cout << -1 << endl;
            return;
        }
        cout << size - 2 << endl;
        for (int j = size - 3; j >= 0; j--) {
            cout << j + 1 << " " << j + 2 << " " << size << endl;
        }
    } else {
        for (int j = size - 2; j >= 0; j--) {
            if (arr[j] > arr[j+1]) {
                cout << -1 << endl;
                return;
            }
        }
        cout << 0 << endl;
    }
}