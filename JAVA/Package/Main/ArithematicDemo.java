import java.util.Scanner;
import arithmetic.Add;
import arithmetic.Substract;
import arithmetic.Multiply;
import arithmetic.Division;
import arithmetic.operation;
public class ArithmeticDemo
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter two numbers:");
        double a = sc.nextDouble();
        double b = sc.nextDouble();
             
        operation add = new Add();
        operation sub = new Substract();
        operation mul = new Multiply();
        operation div = new Division();
        
        System.out.println("Addition: " + a + " + " + b + " = " + add.calculate(a, b));
        System.out.println("Subtraction: " + a + " - " + b + " = " + sub.calculate(a, b));
        System.out.println("Multiplication: " + a + " * " + b + " = " + mul.calculate(a, b));
        System.out.println("Division: " + a + " / " + b + " = " + div.calculate(a, b));
        sc.close();
    }
    
}
//output
// Enter two numbers:
// 20
// 10
// Addition: 20.0 + 10.0 = 30.0
// Subtraction: 20.0 - 10.0 = 10.0
// Multiplication: 20.0 * 10.0 = 200.0
// Division: 20.0 / 10.0 = 2.0
