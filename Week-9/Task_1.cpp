#include <iostream>
using namespace std;

int main() {
    int n, capacity;
    cout << "Enter number of pages: ";
    cin >> n;

    int pages[n];

    cout << "Enter reference string: ";
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter frame capacity: ";
    cin >> capacity;

    int frames[capacity], time[capacity];

    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    int faults = 0, t = 0;

    for (int i = 0; i < n; i++) {
        int pos = -1, found = 0;

        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                time[j] = ++t;
                found = 1;
                break;
            }
        }

        if (!found) {
            faults++;

            for (int j = 0; j < capacity; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if (pos == -1) {
                pos = 0;

                for (int j = 1; j < capacity; j++) {
                    if (time[j] < time[pos])
                        pos = j;
                }
            }

            frames[pos] = pages[i];
            time[pos] = ++t;
        }

        cout << "Page " << pages[i] << ": ";

        for (int j = 0; j < capacity; j++)
            cout << frames[j] << " ";

        cout << endl;
    }

    cout << "Total Page Faults: " << faults << endl;

    return 0;
}