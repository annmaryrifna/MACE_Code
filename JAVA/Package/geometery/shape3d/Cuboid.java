//geometery/shape3d/Cuboid.java
package geometery.shape3d;
import geometery.shape2d.Rectangle;
public class Cuboid extends Rectangle
{
public double height;
public Cuboid (double l,double w,double h)
{
super(l,w);
this.height=h;
}
public double volume()
{
return area()*height;
}
}