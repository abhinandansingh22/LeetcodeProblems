class Solution {
    public int longestPalindrome(String s) {
        int [] chars = new int[128];
        int len = s.length();
    	for(char ch : s.toCharArray()) {
    		chars[ch - 'A'] ^= ch;
    		len = len + (chars[ch - 'A'] == 0 ? 1 : -1);
    	}
    	return len == s.length() ? len : len + 1;
    }
}