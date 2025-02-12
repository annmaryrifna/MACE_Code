interface Printable
{
    public void display();
    public void show();
}
interface Computable
{
    public double area();
        public double volume();
            public double perimeter();
}
interface Drawable
{
    public void draw();
}
class Rectangle implements Printable,Computable,Drawable
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
    public double volume()
    {
        return -1;
    }
    public void display()
    {
        System.out.println("Rectangle("+l+","+b+")");
    }
    public void show()
    {}
    public void draw()
    {
        System.out.println("Drawing Rectangle--");
    }
}
class Circle implements Printable,Computable,Drawable
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
     public double volume()
    {
        return -1;
    }
    public void display()
    {
        System.out.println("Circle("+r+")");
    }
    public void show()
    {}
    public void draw()
    {
        System.out.println("Drawing Circle--");
    }
}
class InterfaceDemo2
{
    public static void main(String arg[])
    {
     Rectangle r= new Rectangle(2,3);
     r.display();
     r.show();
     System.out.println("Area of Rectangle:"+r.area());
          System.out.println("Volume of Rectangle:"+r.volume());
               System.out.println("Perimeter of Rectangle:"+r.perimeter()+"\n");
    Circle c= new Circle(3);
     c.display();
     c.show();
     System.out.println("Area of Circle:"+c.area());
     System.out.println("Volume of Circle:"+c.volume());
    System.out.println("Perimeter of Circle:"+c.perimeter());
    }
}
