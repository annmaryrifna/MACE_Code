//geometery/shape2d/Rectangle.java
package geometery.shape2d;
import geometery.interfaces.*;
public class Rectangle implements calArea,calPerimeter
{
public double l,w;
public Rectangle(double l,double w)
{
this.l=l;
this.w=w;
}
public double area()
{
return l*w;
}
public double perimeter()
{
return 2*(l+w);
}
public String toString()
{
return "R("+l+","+w+")";
}
}