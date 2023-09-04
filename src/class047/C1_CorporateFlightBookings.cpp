#include <vector>
using namespace std;

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> cnt(n + 2, 0);
    for (auto& book : bookings) {
        cnt[book[0]] += book[2];
        cnt[book[1] + 1] -= book[2];
    }
    
    for (int i = 1; i < cnt.size(); ++i) {
        cnt[i] += cnt[i - 1];
    }
    
    return vector<int>(cnt.begin() + 1, cnt.begin() + n + 1);
}
