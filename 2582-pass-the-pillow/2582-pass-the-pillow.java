class Solution {
    public int passThePillow(int n, int time) {
        if(time < n){
            return time+1;
        }
        int pos = time % (n-1);
        int turn = (time/(n-1))+1;
        if(turn %2 == 0){
            //last
            return n-pos;
        }
        //starting
        return pos+1;

    }
}