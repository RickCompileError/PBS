class Solution {
public:

    string encode(vector<string>& strs) {
        string enstr = "";
        for (auto& str: strs) {
            enstr += (char)str.size();
            enstr += str;
        }
        return enstr;
    }

    vector<string> decode(string s) {
        vector<string> destr;
        int idx = 0;
        while (idx < s.size()) {
            int len = s[idx];
            destr.push_back(s.substr(++idx, len));
            idx += len;
        }
        return destr;
    }
};

