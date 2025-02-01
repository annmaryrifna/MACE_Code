import java.util.Scanner;

public class Fibonacci
{
       public static void Fibo(int n)
 {
        int a=0,b=1,c=0,i;
          System.out.print("Fibonacci Series: " + a + " " + b + " "); 
        
        for ( i = 3; i <= n; i++) 
{  
            c = a + b;
            a = b;
            b = c;
            System.out.print(c + " "); 
        }
        
        System.out.println(); // Move to the next line after printing series
    }

    public static void main(String[] args) 
{ 
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number: ");
        int num = sc.nextInt();
        
            Fibo(num);
        
        sc.close();
    }
}
