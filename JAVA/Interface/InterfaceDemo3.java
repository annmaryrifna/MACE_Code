interface Comparable
{
    public double volume();
    int compareByVolume(Comparable other);
}
class Cuboid implements Comparable
{
    double l,w,h;
    Cuboid(double l,double w,double h)
    {
        this.l=l;
        this.w=w;
        this.h=h;
    }
    public double volume()
    {
        return l*w*h;
    }
    public int compareByVolume(Comparable other)
    {
        if (volume()>other.volume())
            return 1;
        else if(volume()< other.volume())
           return -1;
        else
           return 0;
    }
    public String toString()
    {
        return "Cuboid("+volume()+")";
    }
}
class Cylinder implements Comparable
 {
    double r,h;
    Cylinder(double r,double h)
    {
        this.r=r;
        this.h=h;
    }
    public double volume()
    {
        return 3.14*r*r*h;
    }
    public int compareByVolume(Comparable other)
    {
        if (volume()>other.volume())
            return 1;
        else if(volume()< other.volume())
           return -1;
        else
           return 0;
    }
    public String toString()
    {
        return "Cylinder("+volume()+")";
    }
}
class InterfaceDemo3
{
    public static void main(String arg[])
    {
        Cuboid c1=new Cuboid(2,3,2);
        Cylinder c2=new Cylinder(3,2);
        int result=c1.compareByVolume(c2);
        if (result >0)
        System.out.println(c1 +"is smaller than"+c2);
        else if(result < 0)
        System.out.println(c2 +"is larger than"+c1);
        else
         System.out.println(c1 +"is the same as "+c2);
    }
}
