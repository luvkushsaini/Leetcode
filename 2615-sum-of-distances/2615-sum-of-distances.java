import java.util.*;

class Solution {

    int pos(int i, List<long[]> list) {
        int low = 0;
        int high = list.size() - 1;
        int ind = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (list.get(mid)[0] > i) {
                high = mid - 1;
            } else {
                ind = mid;  
                low = mid + 1;
            }
        }

        return ind;
    }

    public long[] distance(int[] nums) {
        int n = nums.length;
        Map<Integer, List<long[]>> mp = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            mp.putIfAbsent(num, new ArrayList<>());
            mp.get(num).add(new long[]{i, 0, 0});
        }

        for (List<long[]> list : mp.values()) {

            for (int i = 1; i < list.size(); i++) {
                int diff = (int)(list.get(i)[0] - list.get(i - 1)[0]);
                list.get(i)[1] = list.get(i - 1)[1] + (long) diff * i;
            }

            for (int i = list.size() - 2; i >= 0; i--) {
                int diff = (int)(list.get(i + 1)[0] - list.get(i)[0]);
                list.get(i)[2] = list.get(i + 1)[2] + (long) diff * (list.size() - i - 1);
            }
        }

        long[] ans = new long[n];

        for (int i = 0; i < n; i++) {
            int num = nums[i];

            int idx = pos(i, mp.get(num)); 

            long[] arr = mp.get(num).get(idx);
            ans[i] = arr[1] + arr[2];
        }

        return ans;
    }
}