// Time: O(n), Space: O(1)
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = INT_MAX, num, result;
        while (true) {
            num = rand() % (right - left + 1) + left;
            result = guess(num);
            if (result > 0) left = num;
            else if (result < 0) right = num;
            else return num;
        }
    }
};