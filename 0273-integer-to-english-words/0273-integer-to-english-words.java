class Solution {
    String[] ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    String[] tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    String[] thousands = {"", "Thousand", "Million", "Billion"};

    public String numberToWords(int num) {
        if (num == 0 ) return "Zero";

        int i = 0;
        String words = "";

        while(num > 0){
            if(num % 1000 != 0){
                words = strgen(num % 1000) + thousands[i] + " " + words;
            }
            num = num / 1000;
            i++;
        }
        return words.trim();
    }

    public String strgen(int num){
        if(num == 0) return "";
        else if (num < 20) return ones[num] + " ";
        else if (num < 100) return tens[num / 10] + " " + strgen(num%10);
        else return ones[num / 100] + " Hundred " + strgen(num%100);
    }
}