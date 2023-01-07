class Solution {
public:
    int formula(vector<int>& p1, vector<int>& p2){
    return pow(p2[0]-p1[0],2)+pow(p2[1]-p1[1],2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
            unordered_set <int> s;
            s.insert(formula(p1, p2));
            s.insert(formula(p2, p3));
            s.insert(formula(p3, p4));
            s.insert(formula(p4, p1)),
            s.insert(formula(p1, p3));
            s.insert(formula(p2, p4));

            return s.size() == 2 && (!s.count(0));
    }
};