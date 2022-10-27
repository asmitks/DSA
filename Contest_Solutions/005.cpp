#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (m % n != 0) {
        cout << -1 << endl;
    } else {
    int ayush = 0;
    int goel = m / n;
    while (goel % 2 == 0) {
        ayush++;
        goel /= 2;
    }
    while (goel % 3 == 0) {
        ayush++;
        goel /=3;
    }
    if (goel == 1) {
        cout << ayush << "\n";
    } else {
        cout << -1 << "\n";
    }
    
}
	// your code goes here
	return 0;
}

