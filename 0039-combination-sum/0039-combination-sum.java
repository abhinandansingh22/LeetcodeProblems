class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        find(candidates, 0, target, new ArrayList<>(), ans);
        return ans;
    }
    private void find(int[] arr, int index, int target, ArrayList<Integer> ds, List<List<Integer>> ans) {
        if(index == arr.length) {
            if(target == 0) {
                ans.add(new ArrayList<>(ds));
            }
            return;
        }
        if(arr[index] <= target) {
            ds.add(arr[index]);
            find(arr, index, target - arr[index], ds, ans);
            ds.remove(ds.size() -1);
        }
        find(arr, index+1, target, ds, ans);
    }
}