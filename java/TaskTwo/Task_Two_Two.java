import java.util.Random;
import java.util.Arrays;
public class Task_Two_Two {
    public static void main(String[] args) {
        int arr[] = new int[1000];
        Random rand = new Random();
        for (int i = 0; i < arr.length; i++) {
            arr[i] = rand.nextInt(1000);
        }
        int target = 553;
        Arrays.sort(arr);
        int left = 0;
        int right = arr.length - 1;
        long startTime = System.nanoTime();
        int index = -1; 
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                index = mid;
                break;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        long endTime = System.nanoTime();
        if (index != -1) {
            System.out.println("Target " + target + " found at index: " + index);
        } else {
            System.out.println("Target " + target + " not found.");
        }

        System.out.println("Binary search time (nanoseconds): " + (endTime - startTime));
    }
}
