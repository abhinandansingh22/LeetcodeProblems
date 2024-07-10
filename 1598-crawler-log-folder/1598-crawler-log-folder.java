class Solution {
    public int minOperations(String[] logs) {
        int tot=0;
        for(String a:logs){
            if(a.equals("./"))
            continue;
            else if(a.equals("../")){
            if(tot>0)
            tot--;
            }
            else
            tot++;
        }
        return tot;
    }
}