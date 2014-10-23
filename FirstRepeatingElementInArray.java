public class FirstRepeatingElementInArray {
   public static void main(String[] args) {
      meth();
   }

   public static void meth()
   {
      int[] arr = {10, 5, 3, 4, 3, 5, 6};
      //Output: 5 [5 is the first element that repeats]
      int min=0;
      for(int i=arr.length-1;i>min;i--)
      {
         if(arr[min]==arr[i])
         {
            System.out.println("Repeating element is:\t"+arr[min]);
         }
         else
         {
            min++;
         }
      }
   }
}
