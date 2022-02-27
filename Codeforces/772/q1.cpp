#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        int result = 0;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int next;
            cin >> next;
            result |= next;
        }
        cout << result << endl;
    }
    return 0;
}