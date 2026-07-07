class Solution {
public:
    string convert(string s, int numRows) {
        // handle single row
        if (numRows == 1) return s;

        string ret_s = "";
        for (int i = 0; i < numRows; i++) {
            int index = i;
            bool top_row = (i == 0);
            bool last_row = (i == numRows - 1);
            bool dir = !last_row; // true: down, false: up

            while (index < s.length()) {
                ret_s += s[index];

                if (dir) {
                    index += 2*(numRows - i - 1);
                } else {
                    index += 2*i;
                }
                
                if (!(last_row || top_row)) dir = !dir;
            }
        }
        return ret_s;
    }
};