package leetcode.Array;
import java.util.ArrayDeque;
import java.util.Deque;

// Find Min Sum of sub arrays
// input [1,3,2] - [1] [2] [3] [1,2] [2,3] [1,2,3]
// imbalance = min num - max num within an array - ex: [1] min=1 max=1 -> 1-1=0
// 1-1 + 2-2 + 3-3 + 2-1 + 3-2 + 3-1
// -> sum = 0 + 0 + 0 + 1 + 1 + 2 = 4

public class MinSumOfSubArray {
    public static void main(String[] args) {
        int[] arr = new int[]{4,7,9};
        System.out.println("Result: " + shipmentImbalance(arr));
    }

    public static int shipmentImbalance(int[] arr) {
        Deque<int []> s = new ArrayDeque<>();
        Deque<int []> s_max = new ArrayDeque<>();

        int res = 0;
        int currentStackVal = 0;
        int currentStackVal1 = 0;

        for(int i = 0; i< arr.length; i++) {
            int currentVal = arr[i];
            int currentCount = 1;

            int currentVal1 = arr[i];
            int currentCount1 = 1;

            while(!s.isEmpty() && s.peek()[0]>currentVal) {
                int[] pop = s.pop();
                currentStackVal -= pop[0]*pop[1];
                currentCount+=pop[1];
            }

            while(!s_max.isEmpty() && s_max.peek()[0]<currentVal) {
                int[] pop = s_max.pop();
                currentStackVal1 -= pop[0]*pop[1];
                currentCount1+=pop[1];
            }

            s_max.push(new int[]{currentVal1, currentCount1});
            s.push(new int[] {currentVal, currentCount});
            currentStackVal += currentVal * currentCount;
            currentStackVal1 += currentVal1 * currentCount1;
            res += (currentStackVal1 - currentStackVal);
        }

        return res;
    }
}