class Solution {
    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);  // Step 1: Sort positions

        int low = 1;  // Smallest possible magnetic force
        int high = position[position.length - 1] - position[0];  // Largest possible distance

        int answer = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;  // Try this force
            if (canPlaceBalls(position, m, mid)) {
                answer = mid;        // It's possible → try for a bigger min distance
                low = mid + 1;
            } else {
                high = mid - 1;      // Not possible → try smaller force
            }
        }

        return answer;
    }

    // Helper function to check if we can place m balls with at least 'minDist' separation
    private boolean canPlaceBalls(int[] position, int m, int minDist) {
        int count = 1;  // Place first ball at first position
        int lastPlaced = position[0];

        for (int i = 1; i < position.length; i++) {
            // If this position is at least 'minDist' from the last one, we place a ball
            if (position[i] - lastPlaced >= minDist) {
                count++;
                lastPlaced = position[i];  // Update where last ball was placed
                if (count == m) return true;  // Early exit: all balls placed
            }
        }

        return false;  // Could not place all m balls with this min distance
    }
}
