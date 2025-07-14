class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(candidates);  // Step 1: sort to handle duplicates
        backtrack(candidates, target, 0, new ArrayList<>(), res);
        return res;
    }

    private void backtrack(int[] nums, int target, int start, List<Integer> path, List<List<Integer>> res) {
        if (target == 0) {
            res.add(new ArrayList<>(path));  // Found a valid combination
            return;
        }

        for (int i = start; i < nums.length; i++) {
            // Step 2: Skip duplicates at same depth
            if (i > start && nums[i] == nums[i - 1]) continue;

            // Step 3: If current number exceeds target, break early (sorted array)
            if (nums[i] > target) break;

            path.add(nums[i]); // choose
            backtrack(nums, target - nums[i], i + 1, path, res); // explore (i+1, use once)
            path.remove(path.size() - 1); // un-choose
        }
    }
}