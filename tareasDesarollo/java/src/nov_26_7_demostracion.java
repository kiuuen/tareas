/*Probar que  (n*n*n) / (n+n+n) = 37 de n = 1 hasta n = 9 */

import java.util.Scanner;
import java.lang.Thread;
public class nov_26_7_demostracion {
    public static void main(String[] args) {
        boolean repetir = true;
        Scanner sc = new Scanner(System.in);
        do {
        int n = 1;
        System.out.println("Introduce que n deseas probar, (o pon "+"10"+" para para probar todas las n): ");
        int entrada = sc.nextInt();
        sc.nextLine();
            if (entrada <= 0 || entrada > 10) {
                System.out.println("Con esos valores no funciona esta demostración, intenta del 1 al 9");
            }
            if (entrada >0 && entrada <11) {
                if (entrada != 10) {
                    n = entrada;
                    do {
                        System.out.println("\n\nCon n = "+n+"\n");
                        System.out.print("   "+(n)+""+(n)+""+(n)+"            "+(n)+""+(n)+""+(n)+"\n---------  =  ---------- =  "+((n*100)+(n*10)+(n))/(n+n+n)+"\n"+n+" + "+n+" + "+n+"         "+(n+n+n));
                        n++;
                    } while(n==1); // como n aumento solo itera una vez
                    System.out.println("\n\nEsto nos demuestra que nnn/n+n+n da 37 para n = "+entrada);
                }
                if (entrada == 10) {
                    do {
                        System.out.println("\n\nCon n = "+n+"\n");
                        System.out.print("   "+(n)+""+(n)+""+(n)+"            "+(n)+""+(n)+""+(n)+"\n---------  =  ---------- =  "+((n*100)+(n*10)+(n))/(n+n+n)+"\n"+n+" + "+n+" + "+n+"         "+(n+n+n));
                        n++;
                    } while(n < entrada); // ahora del 1 al 9
                    System.out.println("\n\nEsto nos demuestra que nnn/n+n+n da 37 para n > 0 && n < 10");
                }
            }
            System.out.println("Otra vez? s/n");
            String eleccion = sc.nextLine();
            if (eleccion.toLowerCase().equals("n")) {
                repetir = false;
            } else {
                repetir = true;
            }
        } while(repetir == true);
            System.out.println();
            int x = 1 ;
            System.out.print("Saliendo ");
            do {
                String j = " . ";
                System.out.print(j);
                try {
                Thread.sleep(500);
                } catch (InterruptedException e) { // es lo que no me gusta de java, pero tan siquiera aprendi de esto (sólo queria hacer un sleep rapido como en python)
                    Thread.currentThread().interrupt();
                    } 
                x++;
            } while (x<4);
            sc.close(); 
    }
}


 // todo fue para dejarlo un poco bonito, la operacion, la demostración realmente sólo es ((n*100)+(n*10)+(n))/(n+n+n) para n>0 && n<10