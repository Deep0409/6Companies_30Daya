class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
         map<pair<int, int>, int>m;
        for(vector<int> &rect : rectangles){
            m[{rect[0],rect[1]}]--;
            m[{rect[2],rect[3]}]--;
            m[{rect[0],rect[3]}]++;
            m[{rect[2], rect[1]}]++;
        }
        int c = 0;
        for(auto i :m){
            c += abs(i.second);
        }
        return c== 4;
    }
};