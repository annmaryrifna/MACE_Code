import java.util.Scanner;
class AreaDemo
{
    public int Rectangle(int l,int b)
    {
        return(l*b);
    }
    public double Rectangle(double l,double b)
    {
        return (l*b);
    }
    public int Square(int a)
    {
        return(a*a);
    }
    public double Square(double a)
    {
        return (a*a);
    }
    public double Circle(double r)
    {
        return (3.14*r*r);
    }
    public double Triangle(double b,double h)
    {
        return (0.5*b*h);
    }
    public static void main(String []arg)
    {
        Scanner sc=new Scanner(System.in);
        AreaDemo a=new AreaDemo();
        System.out.print("Enter length and bredth:");
        int l1=sc.nextInt();
        int b1=sc.nextInt();
        System.out.println("Area of rectangle in integer:"+a.Rectangle(l1,b1)+"\n-------------------------");

         System.out.print("Enter length and bredth:(in double)");
        double l2=sc.nextDouble();
        double b2=sc.nextDouble();
        System.out.println("Area of rectangle (in double):"+a.Rectangle(l2,b2)+"\n-------------------------");

         System.out.print("Enter side :"); 
        int a1 =sc.nextInt();
        System.out.println("Area of square in integer:"+a.Square(a1)+"\n-------------------------");

         System.out.print("Enter  side:(in double)");
        double a2=sc.nextDouble();
        System.out.println("Area of square(in double):"+a.Square(a2)+"\n-------------------------");

        System.out.print("Enter  radius:(in double)");
        double r =sc.nextDouble();
        System.out.println("Area of circle  :"+a.Circle(r)+"\n------------------------");
        
         System.out.print("Enter  breadth,height:(in double)");
        double br=sc.nextDouble();
        double h=sc.nextDouble();
        System.out.println("Area of square in integer:"+a.Triangle(br,h)+"\n--------------------");
    }
}


