// Time: O(n), Space: O(n)
class Spreadsheet {
private:
    int rows;
    vector<vector<int>> sheet;

    vector<int> getPos(string cell) {
        int r = stoi(cell.substr(1)) - 1;
        int c = cell[0] - 'A';
        return {r, c};
    }

    int toNum(string str) {
        if (isdigit(str[0])) {
            return stoi(str);
        }
        vector<int> pos = getPos(str);

        return sheet[pos[0]][pos[1]];
    }

public:
    Spreadsheet(int rows): rows(rows) {
        sheet = vector(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        vector<int> pos = getPos(cell);
        sheet[pos[0]][pos[1]] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
    }
    
    int getValue(string formula) {
        int plusPos = formula.find('+');
        string leftStr = formula.substr(1, plusPos - 1);
        string rightStr = formula.substr(plusPos + 1);
        int leftNum = toNum(leftStr);
        int rightNum = toNum(rightStr);

        return leftNum + rightNum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
