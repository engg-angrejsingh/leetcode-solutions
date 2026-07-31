class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.empty() || words.empty()) return ans;

        int wordLen = words[0].size();
        int numWords = words.size();
        int totalLen = wordLen * numWords;

        if (s.size() < totalLen) return ans;

        unordered_map<string, int> target;
        for (auto &w : words)
            target[w]++;

        for (int offset = 0; offset < wordLen; offset++) {
            unordered_map<string, int> window;
            int left = offset;
            int count = 0;

            for (int right = offset; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);

                if (target.count(word)) {
                    window[word]++;
                    count++;

                    while (window[word] > target[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == numWords) {
                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return ans;
    }
};

/*
⏱️ Time Complexity: O(n × m × l)

Reason:
- n = length of the string `s`
- m = number of words
- l = length of each word
- We use a sliding window for each possible offset (0 to l-1).
- Each word-sized chunk is processed at most once per offset, making the overall complexity O(n × m × l).

💾 Space Complexity: O(m × l)

Reason:
- Two hash maps (`target` and `window`) store at most `m` unique words.
- Each word has length `l`.
- Therefore, the auxiliary space is O(m × l).
*/