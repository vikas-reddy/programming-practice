public class BubbleSort {
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
          i = 0,
          j = 0,
          temp = 0;

      for (i = len - 2; i >= 0; i--) {
         for (j = 0; j <= i; j++) {
            if (array[j] > array[j+1]) {
               temp = array[j+1];
               array[j+1] = array[j];
               array[j] = temp;
            }
         }
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
