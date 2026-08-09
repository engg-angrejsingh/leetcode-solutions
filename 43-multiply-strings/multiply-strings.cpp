class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int n = num1.size();
        int m = num2.size();

        vector<int> result(n + m, 0);

        // Multiply digit by digit
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int a = num1[i] - '0';
                int b = num2[j] - '0';

                int product = a * b;
                int pos1 = i + j;
                int pos2 = i + j + 1;

                int sum = product + result[pos2];

                result[pos2] = sum % 10;
                result[pos1] += sum / 10;
            }
        }

        // Convert vector to string, skipping leading zeros
        string ans;
        int i = 0;

        while (i < result.size() && result[i] == 0)
            i++;

        while (i < result.size())
            ans += char(result[i++] + '0');

        return ans.empty() ? "0" : ans;
    }
};

/*
⏱️ Time Complexity: O(n × m)

Reason:
- We multiply every digit of num1 with every digit of num2.
- If n is the length of num1 and m is the length of num2,
  there are n × m digit multiplications.
- Converting the result to a string takes O(n + m).

💾 Space Complexity: O(n + m)

Reason:
- The result array stores at most n + m digits.
- The output string also requires O(n + m) space.
*/