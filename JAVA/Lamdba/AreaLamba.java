import java.util.Scanner;
interface Dim
{
    double area(int x);
}
public class AreaLambda
{
    public static void main(String arg[])
    {
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter the side and radius:"); 
        int s=sc.nextInt();
        int r1=sc.nextInt();
     Dim square=(x)->x*x;
     System.out.println("Area of square:"+square.area(s));
     Dim cube=(x)->x*x*x;
     System.out.println("Area of cube:"+cube.area(s));
     Dim circle=(r)->3.14*r*r;
     System.out.println("Area of circle:"+circle.area(r1));
     Dim sphere=(r)->4*3.14*r*r;
     System.out.println("Area of sphere:"+sphere.area(r1));
    }
}
