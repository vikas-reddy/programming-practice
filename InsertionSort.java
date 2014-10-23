public class InsertionSort {
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
      int i = 0,
          j = 0,
          len = array.length,
          temp = 0;

      for (i = 1; i < len; i++) {
         // Sorted:   array[0..i-1]
         // Unsorted: array[i..len-1]
         // insert array[i] into the appropriate position in array[0..i-1]
         temp = array[i];
         for (j = i-1; j >= 0 && array[j] > array[i]; j--) {
            array[j+1] = array[j];
         }
         array[j+1] = temp;

         System.out.print(i + " ;");
         print(array);
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
