// Time: O(n), Space: O(n)
class Solution {
public:
    string makeFancyString(string s) {
        int count=0;
        char now=' ';
        string ans;
        for (char i: s){
            if (i!=now){
                count=0;
                now=i;
            }
            if (count<2){
                ans+=i;
                count++;
            }

        }
        return ans;
    }
};
