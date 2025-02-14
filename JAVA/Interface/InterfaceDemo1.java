import java.util.Scanner;
interface Calculate
{
    public double area();
    public double perimeter();
}
class Rectangle implements Calculate
{
    double l,b;
    Rectangle(double l,double b)
    {
        this.l=l;
        this.b=b;
    }
    public double area()
    {
        return l*b;
    }
    public double perimeter()
    {
        return 2*(l+b);
    }
}
 class Circle implements Calculate
{
    double r;
    Circle(double r)
    {
        this.r=r;
    }
    public double area()
    {
        return 3.14*r*r;
    }
    public double perimeter()
    {
        return 2*3.14*r;
    }
}
class InterfaceDemo1
{
 public static void main(String arg[])
 {
     Scanner in =new Scanner(System.in);
     int ch;
     do
        {
        System.out.println("--Menu\n1.Rectangle area & Rectangle perimeter\n2.Circle area & Circle perimete\n3.Exit!\n");
        System.out.print("Enter the choice:");
        ch=in.nextInt();
        switch(ch)
        {
            case 1:
                System.out.print("Enter the length and breath:");
                double l=in.nextDouble();
                double b=in.nextDouble();
                Rectangle r=new Rectangle(l,b);
                System.out.println("Area of Rectangle:"+r.area());
                System.out.println("Perimeter of Rectangle:"+r.perimeter());
            break;
            case 2: 
                 System.out.println("Enter the radius:");
                 double ra=in.nextDouble();
                 Circle c=new Circle(ra);
                 System.out.println("Area of Circle:"+c.area());
                 System.out.println("Perimeter of Circle:"+c.perimeter());
            break;
            case 3:
                System.out.println("Exiting----");
            break;
            default:
                System.out.println("Invalid choice!");
        }
        }while(ch!=3);
     }
 }
