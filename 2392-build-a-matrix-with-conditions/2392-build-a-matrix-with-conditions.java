class Solution {
    public static int[] topologicalSort(int[][] adj,int k){
        ArrayList<ArrayList<Integer>> arr=new ArrayList<>();
        for(int i=0;i<=k;i++){
            arr.add(new ArrayList<>());
        }
        int[] inDegree=new int[k+1];
        for(int[] a:adj){
            arr.get(a[0]).add(a[1]);
            inDegree[a[1]]++;
        }
        Queue<Integer> pq=new LinkedList<>();
        for(int i=1;i<=k;i++){
             if(inDegree[i]==0){
                pq.add(i);
             }
        }
        int count=0;
        int[] res=new int[k];
        int l=0;
        while(!pq.isEmpty()){
               int d=pq.poll();
               res[l++]=d;
               count++;
               for(Integer s:arr.get(d)){
                  inDegree[s]=inDegree[s]-1;
                  if(inDegree[s]==0){
                    pq.add(s);
                  }
               }
        }
        if(count<k){
            return new int[]{};
        }
        return res;

    }
    public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
        int[][] matrix=new int[k][k];
        int[] mat1=topologicalSort(rowConditions,k);
        int[] mat2=topologicalSort(colConditions,k);
        if(mat1.length==0||mat2.length==0){
            return new int[][]{};
        }
        for(int i=0;i<mat1.length;i++){
            for(int j=0;j<mat2.length;j++){
                if(mat1[i]==mat2[j]){
                    matrix[i][j]=mat1[i];
                }
            }
        }
        return matrix;

        
    }
}