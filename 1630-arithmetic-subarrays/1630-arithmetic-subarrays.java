class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        ArrayList<Boolean> ans = new ArrayList<Boolean>();
        ArrayList<Integer> dup = new ArrayList<>();
        
        for(int i =0 ; i < l.length ; i++)
        {
            int c=0;
            dup.clear();
            for(int j = l[i] ; j <= r[i] ; j++ )
            {
                dup.add(nums[j]);
            }
            Collections.sort(dup);
            for(int k = 0 ; k < dup.size()-1 ; k++)
            {
                if(dup.get(1)-dup.get(0)!=dup.get(k+1)-dup.get(k))
                {
                c++;
                break;
                }
            }
            if(c==0)
            ans.add(true);
            else
            ans.add(false);
        }
        return ans;
    }
}