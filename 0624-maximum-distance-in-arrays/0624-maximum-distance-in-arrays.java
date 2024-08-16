class Solution {
    public int maxDistance(List<List<Integer>> arrays) {

        int res=Integer.MIN_VALUE;
        int mini1=Integer.MAX_VALUE;;
        int indmin1=-1;
        for(int i=0;i<arrays.size();i++){
            int tempmin=arrays.get(i).get(0);
            if(tempmin<mini1){
                indmin1=i;

            mini1=Math.min(mini1,tempmin);
            }
        }

        int maxi2=Integer.MIN_VALUE;
        int indmax2=-1;
    
        for(int i=0;i<arrays.size();i++){
            int tempmax=arrays.get(i).get(arrays.get(i).size()-1);
            if(tempmax>maxi2&&i!=indmin1){
                indmax2=i;
            maxi2=Math.max(maxi2,tempmax);
            }

        
        }

        int maxi1=Integer.MIN_VALUE;
        int indmax1=-1;
        for(int i=0;i<arrays.size();i++){
            int tempmax=arrays.get(i).get(arrays.get(i).size()-1);
            if(tempmax>maxi1)
                indmax1=i;
            maxi1=Math.max(maxi1,tempmax);
        }
        int mini2=Integer.MAX_VALUE;;
        int indmin2=-1;
        int temp = 2;
        for(int i=0;i<arrays.size();i++){
            int tempmin=arrays.get(i).get(0);
            if(tempmin<mini2&&i!=indmax1){
                indmin2=i;

            mini2=Math.min(mini2,tempmin);
            }
        }
        
        return maxi2-mini1>maxi1-mini2?maxi2-mini1:maxi1-mini2;
        
    }
}