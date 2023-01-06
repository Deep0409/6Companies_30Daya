class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> s;

        for(string x:t)
        {
            if(isdigit(x[0]) || (x[0] == '-' && x.size() > 1) ) s.push(stoi(x));

            else
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();

                     if(x=="+") s.push(b+a);
                else if(x=="-") s.push(b-a);
                else if(x=="/") s.push(b/a);
                else s.push(b*a);
            }
        }
        return s.top();
    }
};