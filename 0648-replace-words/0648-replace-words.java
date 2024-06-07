class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
       
     Collections.sort(dictionary, Comparator.comparingInt(String::length));
     String[] words = sentence.split(" ");
     for(int i=0;i<words.length;i++){
        String word = words[i];
        String replacement = word;
        for (String root : dictionary) {
                if (word.startsWith(root) && root.length() < replacement.length()) {
                    replacement = root;
                }
                words[i] = replacement;
            }
     }
      String result = String.join(" ", words);
      return result;
   
        
    
    }
}