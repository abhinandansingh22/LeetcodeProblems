class Pair{
    String name;
    int height;

    public Pair(String name, int height){
        this.name = name;
        this.height = height;
    }
}
class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> b.height - a.height);
        int n = names.length;
        for(int i =0; i < heights.length; i++){
            pq.add(new Pair(names[i], heights[i]));
        }
        String[] ans = new String[n];
        for(int i =0 ; i < n ; i++){
            Pair curr = pq.poll();
            ans[i] = curr.name;
        }
        return ans;
    }
}