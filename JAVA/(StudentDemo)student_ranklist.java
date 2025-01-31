import java.util.Scanner;
class Student
{

    int rollno;
    String name;
    int marks;
    public Student ()
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Roll nO:");
        rollno=sc.nextInt();
        sc.nextLine();
        System.out.print("Name:");
        name=sc.nextLine();
        System.out.println("Marks");
        marks=sc.nextInt();
        sc.nextLine();
        //sc.close();
    }
    public Student(int roll, String name, int marks) 
    {

        rollno = roll;

        this.name = name;

        this.marks = marks;

    }
    public void display()
    {
        System.out.println("   "+rollno+"    "+name+"    "+ marks);
    }
}
public class StudentDemo
{
    public static void  sortStud(Student s[],int n)
    {
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                if (s[i].marks<s[j].marks)
                {
                    Student temp=s[i];
                    s[i]=s[j];
                    s[j]=temp;
                }
            }
    }
    public static void main(String [] args)
  {
      Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of students: ");
        int n = sc.nextInt();
    Student s[]=new Student [n];
    for(int i=0;i< n;i++)
     s[i]=new Student();
     sortStud(s,n);
     System.out.println("\n ----------Rank List--------");
     System.out.println("Rank: Rollno  Name  Marks");
        for (int i = 0; i < n; i++) 
        { 
             System.out.print((i + 1) + ". ");
             s[i].display();
        }
  }
}
OUTPUT
Enter the number of students: 3
Roll nO:1
Name:Sam
Marks
67
Roll nO:2
Name:John
Marks
78
Roll nO:3
Name:Anjana 
Marks
97

 ----------Rank List--------
Rank: Rollno  Name    Marks
1.    3      Anjana   97
2.    2      John     78
3.    1      Sam     67
  
