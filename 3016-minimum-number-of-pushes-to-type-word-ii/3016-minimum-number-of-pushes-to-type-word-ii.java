class Solution {
    public int minimumPushes(String word) {
         int[] a = new int[26];
         for(int i=0;i<word.length();i++)
         {
            int ch = word.charAt(i)-'a';
            a[ch]++;
         }
         Arrays.sort(a);
         int n = a.length;
        for (int i = 0; i < n / 2; i++) { 
           int t = a[i]; 
            a[i] = a[n - i - 1]; 
            a[n - i - 1] = t; 
        } 
        int ans=0;
        for(int i =0;i<a.length;i++)
        {
            ans += a[i] *(i/8+1);
        }
        return ans;
    }
}