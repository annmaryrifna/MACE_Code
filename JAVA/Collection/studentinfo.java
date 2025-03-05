
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
class studentinfo
{
    public static void main(String arg[])
    {
        HashMap <Integer,String>si=new HashMap<>();
        si.put(101, "John");
        si.put(102, "SAM");
        si.put(103, "Sara");
        System.out.println("Student with ID 101: " + si.get(101));
        System.out.println("Student with ID 102: " + si.get(102));
        System.out.println("Student with ID 103: " + si.get(103));
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Student ID to search: ");
        int id = sc.nextInt();    
        System.out.println("Student Name: " + si.get(id));
    }
}
