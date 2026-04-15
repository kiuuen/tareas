public class hola {
   public static void main(String[] args) {
      int[] A = {1, 2, 10, 4, 5}; // A = [1, 2, 3, 4, 5]
      int[] B = {4, 5, 6, 7, 8};
      int[] C = {};
      int[] D;
      // imprime todos los elementos de B
      // B.length = 5
      System.out.print("\nTamano de A: "+ A.length + "\nElementos de A: ");
      for (int n : A) {
         System.out.println(n + " ");
      }
   }
}
/*  operadores logicos

& and
| or
! not
xor 
-> entonces
si y solo si

- teoria de conjuntos A = [1, 2, 3, 4, 5], B = [4, 5, 6, 7, 8]
A ( 1 2 3 4 5) B ( 4 5 6 7 8 )
& and: interseccion entre dos conjuntos
A n B = [4, 5]
| or: union entre dos conjuntos
A U B = [1, 2, 3, 4, 5, 6, 7, 8]
- bits
byte = 8 bits
int = 4 bytes (32 bits) 2^32 
1 bit : 0 , 1
0      0    0    0   0    0     0     0
128 + 64 + 32 + 16 + 8 +  4  +  2 +   1 =
2^7   2^6  2^5 2^4  2^3  2^2   2^1    2^0
1 0 0 0 0 0 0 0 = 128

| or: si 1 es verdadero, entonces todo es verdadero (1 y 0, 1 y 1)
& and: los 2 tienen que ser verdaderos (1 y 1)

- proposiciones logicas
   p y q     | or  & and    !p (not p)  !q (not q)   
   v   f      v      f           f           v
   v   v      v      v           f           f
   f   v      v      f           v           f
   f   f      f      f           v           v

*/ 
