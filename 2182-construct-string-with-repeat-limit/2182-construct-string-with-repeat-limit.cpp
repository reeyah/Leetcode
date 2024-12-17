class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // Max-heap to store characters by frequency (greatest characters come first)
        priority_queue<pair<char, int>> maxHeap;
        unordered_map<char, int> count;

        // Step 1: Count frequency of each character
        for (char ch : s) {
            count[ch]++;
        }

        // Step 2: Push characters and frequencies into the max-heap
        for (auto &entry : count) {
            maxHeap.push({entry.first, entry.second});
        }

        string ans = "";

        while (!maxHeap.empty()) {
            // Get the most frequent character
            auto [ch, freq] = maxHeap.top();
            maxHeap.pop();

            // Append as many occurrences of 'ch' as possible, limited by 'repeatLimit'
            int use = min(repeatLimit, freq);
            ans.append(use, ch);
            freq -= use;

            // If there are still characters remaining and the next largest character exists
            if (freq > 0) {
                if (maxHeap.empty()) break;  // No other characters to insert, stop early

                // Use the next largest character
                auto [nextCh, nextFreq] = maxHeap.top();
                maxHeap.pop();

                // Append one occurrence of the next character
                ans.push_back(nextCh);
                nextFreq--;

                // Push back the next character into the heap if it still has remaining frequency
                if (nextFreq > 0) {
                    maxHeap.push({nextCh, nextFreq});
                }

                // Push the original character back into the heap for future use
                maxHeap.push({ch, freq});
            }
        }

        return ans;
    }
};
