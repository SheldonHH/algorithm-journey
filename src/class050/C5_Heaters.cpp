class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for(size_t i = 0, j = 0; i < houses.size(); i++){
            // 若i房选j heaters非最优解
            while (j < heaters.size() - 1 && !isBest(houses, heaters, i, j)){
                j++;
            }
            //更新大小半径
            ans = max(ans, abs(heaters[j] - houses[i]));
        }
        return ans;
    }
    bool isBest(const vector<int>& houses, const vector<int>& heaters, size_t i, size_t j){
        // 若当前供暖器是最后且j+1大于j，则准备 j右侧移动
        return j == heaters.size() - 1 ||
                abs(heaters[j] - houses[i]) < abs(heaters[j + 1] - houses[i]);

    }
};