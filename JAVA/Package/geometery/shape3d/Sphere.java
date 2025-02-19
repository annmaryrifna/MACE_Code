//geometery/shape3d/Sphere.java
package geometery.shape3d;
import geometery.shape2d.Circle;
public class Sphere extends Circle
{
public double r;
public Sphere (double r)
{
super(r);
this.r = r;
}
public double volume()
{
    return (4 / 3.0) * 3.14 * r * r * r;
}
}