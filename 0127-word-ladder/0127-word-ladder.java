class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordSet = new HashSet<>(wordList);
        if (!wordSet.contains(endWord)) return 0;

        Queue<String> queue = new LinkedList<>();
        queue.offer(beginWord);
        int steps = 1;

        while (!queue.isEmpty()) {
            int size = queue.size();  // Number of words at current level

            for (int i = 0; i < size; i++) {
                String word = queue.poll();
                
                // Try all 1-letter transformations
                for (int j = 0; j < word.length(); j++) {
                    char[] chars = word.toCharArray();
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        chars[j] = c;
                        String nextWord = new String(chars);

                        if (nextWord.equals(endWord)) return steps + 1;

                        if (wordSet.contains(nextWord)) {
                            queue.offer(nextWord);
                            wordSet.remove(nextWord);  // Mark as visited
                        }
                    }
                }
            }

            steps++;  // Move to next level
        }

        return 0;
    }
}