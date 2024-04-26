#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);  // Speed up cin/cout.
    cin.tie(NULL);                // Untie cin from cout.
    
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        int sum = 0, num;
        while (iss >> num) {
            sum += num;
        }
        cout << sum << endl;
    }

    return 0;
}
