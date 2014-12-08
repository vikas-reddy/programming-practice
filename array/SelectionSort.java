public class SelectionSort {
   public static void print(int[] array) {
      int len = array.length,
          i = 0;
      for (i = 0; i < len; i++) {
         System.out.print(array[i]);
         if (i != len - 1) {
            System.out.print(", ");
         }
      }
      System.out.print("\n");
   }

   public static void sort(int[] array) {
      int len = array.length,
          j = 0,
          minIdx = 0,
          temp = 0;

      for (int i = 0; i < len - 1; i++) {
         // assumption: min is at i
         minIdx = i;

         // find min element in array[i+1..len-1]
         for(j = i+1; j < len; j++) {
            if (array[minIdx] > array[j]) {
               minIdx = j;
            }
         }

         // swap
         temp = array[minIdx];
         array[minIdx] = array[i];
         array[i] = temp;
      }
   }

   public static void main(String args[]) {

      // Random array
      int[] array = new int[10];
      for(int i=0; i < array.length; i++) {
         array[i] = (int)(Math.random() * 100);
      }

      // Input
      System.out.print("input = ");
      print(array);

      // Sorting
      sort(array);

      // Ouput
      System.out.print("output = ");
      print(array);

      return;
   }
}
