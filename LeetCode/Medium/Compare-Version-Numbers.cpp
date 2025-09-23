// Time: O(n), Space: O(1)
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int sz1 = version1.size(), sz2 = version2.size();
        int idx1 = 0, idx2 = 0;
        int dotPos1 = -1, dotPos2 = -1;

        while (idx1 < sz1 || idx2 < sz2) {
            int rev1 = 0, rev2 = 0;
            if (idx1 < sz1) {
                dotPos1 = version1.find('.', idx1);
                if (dotPos1 != string::npos) {
                    rev1 = stoi(version1.substr(idx1, dotPos1));
                    idx1 = dotPos1 + 1;
                } else {
                    rev1 = stoi(version1.substr(idx1));
                    idx1 = sz1;
                }
            }
            if (idx2 < sz2) {
                dotPos2 = version2.find('.', idx2);
                if (dotPos2 != string::npos) {
                    rev2 = stoi(version2.substr(idx2, dotPos2));
                    idx2 = dotPos2 + 1;
                } else {
                    rev2 = stoi(version2.substr(idx2));
                    idx2 = sz2;
                }
            }
            if (rev1 < rev2) {
                return -1;
            } else if (rev1 > rev2) {
                return 1;
            }
        }

        return 0;
    }
};

int compareVersion(string version1, string version2) {
    int i = 0; 
    int j = 0;
    int n1 = version1.size(); 
    int n2 = version2.size();
    
    int num1 = 0;
    int num2 = 0;
    while(i<n1 || j<n2)
    {
        while(i<n1 && version1[i]!='.'){
            num1 = num1*10+(version1[i]-'0');
            i++;
        }
        
        while(j<n2 && version2[j]!='.'){
            num2 = num2*10+(version2[j]-'0');;
            j++;
        }
        
        if(num1>num2) return 1;
        else if(num1 < num2) return -1;
        
        num1 = 0;
        num2 = 0;
        i++;
        j++;
    }
    
    return 0;
}
