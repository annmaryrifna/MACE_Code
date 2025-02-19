//geometery/shape2d/Circle.java
package geometery.shape2d;
import geometery.interfaces.*;
public class Circle implements calArea,calPerimeter
{
double r;
public Circle(double r)
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
public String toString()
{
return "C("+r+")";
}
}