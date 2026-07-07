class Solution {
public:
    int numberOfSubstrings(string s) {
        int freq[3] = {0};
        int left = 0;
        int count = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                freq[s[left] - 'a']--;
                left++;
            }

            count += left;
        }

        return count;
    }
};