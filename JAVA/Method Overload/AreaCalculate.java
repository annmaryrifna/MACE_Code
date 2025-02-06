class AreaCalculate {
    public int Rectangle(int l, int b) {
        return (l * b);
    }

    public double Rectangle(double l, double b) {
        return (l * b);
    }

    public int Square(int a) {
        return (a * a);
    }

    public double Square(double a) {
        return (a * a);
    }

    public double Circle(double r) {
        return (3.14 * r * r);
    }

    public double Triangle(double b, double h) {
        return (0.5 * b * h);
    }

    public static void main(String[] args) {
        AreaDemo a = new AreaDemo();

        int l1 = 2, b1 = 2;
        System.out.println("Area of rectangle (integer): " + a.Rectangle(l1, b1) + "\n-------------------------");

        double l2 = 2.5, b2 = 12.1;
        System.out.println("Area of rectangle (double): " + a.Rectangle(l2, b2) + "\n-------------------------");

        int a1 = 4;
        System.out.println("Area of square (integer): " + a.Square(a1) + "\n-------------------------");

        double a2 = 4.5;
        System.out.println("Area of square (double): " + a.Square(a2) + "\n-------------------------");

        double r = 7.3;
        System.out.println("Area of circle: " + a.Circle(r) + "\n------------------------");

        double br = 6.2, h = 2.1;
        System.out.println("Area of triangle: " + a.Triangle(br, h) + "\n--------------------");
    }
}
