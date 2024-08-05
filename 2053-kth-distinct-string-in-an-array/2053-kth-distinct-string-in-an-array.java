class Solution {
    public String kthDistinct(String[] arr, int k) {
        Map<String, Integer> map = new LinkedHashMap<>();
        for (int i = 0; i < arr.length; i++) {
            map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
        }

        Iterator<Map.Entry<String, Integer>> itr = map.entrySet().iterator();

        while (itr.hasNext()) {
            Map.Entry<String, Integer> e = itr.next();
            if (e.getValue() > 1) {
                itr.remove();
            }
        }

        if (map.size() < k) {
            return "";
        }

        Iterator<String> itr2 = map.keySet().iterator();
        while (k > 1 && itr2.hasNext()) {
            itr2.next();
            itr2.remove();
            k--;
        }
        return itr2.next();
    }
}