class Solution {
    public int minMovesToSeat(int[] seats, int[] students) {
        Arrays.sort(seats);
        Arrays.sort(students);
        int diff=0,sum=0;
        for(int i=0;i<seats.length;i++)
        {
            if(seats[i]!=students[i])
            {
                diff=Math.abs(seats[i]-students[i]);
                sum=sum+diff;
            }
        
        }
return sum;
    }
    
}