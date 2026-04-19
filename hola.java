public class hola {
   public static void main(String[] args) {
      for (int n = 1; n <= 4; n++) {
         for (int m = n; m < 4; m++) {
            System.out.print(" ");
         }
         for (int o = 1; o <= (2*n-1); o++) {
            System.out.print("*");
         }
         System.out.println();
      }
   }
}    