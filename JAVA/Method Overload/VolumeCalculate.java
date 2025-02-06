public class VolumeCalculator 
{
    public double computeVolume(int a) {
        return a*a*a;
    }

    public double computeVolume(double length, double breadth, double height) {
        return length * breadth * height;
    }

    public double computeVolume(double radius) {
        return (4.0 / 3.0) * 3.14 * radius*radius*radius;
    }

    public double computeVolume(double radius, double height) {
        return 3.14 * radius*radius* height;
    }

    public double computeVolume(double radius, int height) {
        return (1.0 / 3.0) * 3.14 * radius*radius  * height;
    }

    public static void main(String[] args) 
    {
        VolumeCalculator vc = new VolumeCalculator();
        System.out.println(vc.computeVolume(3));
        System.out.println(vc.computeVolume(2, 3, 4));
        System.out.println(vc.computeVolume(3.0));
        System.out.println(vc.computeVolume(3, 5.0));
        System.out.println(vc.computeVolume(3, 5));
    }
}
