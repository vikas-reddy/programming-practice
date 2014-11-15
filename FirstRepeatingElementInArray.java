import java.util.*;

public class FirstRepeatingElementInArray {
   public static void main(String[] args) {
      int[] arr = {10, 5, 3, 4, 3, 5, 6};
      // int[] arr = {6, 10, 5, 4, 9, 120, 4, 6, 10};
      int minIdx = -1;
      HashSet<Integer> set = new HashSet<>();

      for (int i = arr.length - 1; i >= 0; i--) {
         if (set.contains(arr[i])) {
            minIdx = i;
         }
         else {
            set.add(arr[i]);
         }
      }

      if (minIdx != -1) {
         System.out.println("Min index of first repeating element: " + minIdx);
      }
      else {
         System.out.println("No repeating elements found");
      }
   }
}
