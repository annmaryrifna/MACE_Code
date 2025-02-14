import java.util.Scanner;
interface Showable
{
    public void show();
}
class Person implements Showable
{
    String name,gender;
    int phoneno;
  Person(String name,String gender,int phoneno)
  {
    this.name=name;
    this.gender=gender;
    this.phoneno=phoneno;
  }
  public void show()
  {
    System.out.println("Student Name:"+name+"\nGender:"+gender+"\nPhone No:"+phoneno+"\n");
  }
}
class Student extends Person implements Showable
{
    String course;
    int score;
    Student(String name,String gender,int phoneno,String course,int score)
    {
        super(name, gender, phoneno);
        this.course=course;
        this.score=score;
    }
     public void show()
  {
    super.show(); 
  }
}
class PGStudent extends Student implements Showable
{
    String researchArea,guide;
    PGStudent(String name,String gender,int phoneno,String course,int score,String researchArea,String guide)
    {
        super(name, gender, phoneno,course,score);
        this.researchArea=researchArea;
        this.guide=guide;
    }
     public void show()
  {
    super.show(); 
  }
}
public class StudentRank
{
    public void sort_score( PGStudent pg[],int n)
    {
      for(int i=0;i<n;i++)
      {
        for(int j=i+1;j<n;j++)
        {
            if(pg[i].score< pg[j].score)
            {
                PGStudent temp =pg[i];
                 pg[i]=pg[j];
                 pg[j]=temp;
            }
        }
      }
    }  
  public static void main(String arg[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("enter no of student:");
        int n=nextInt();
         PGStudent pg[]=new  PGStudent[n];
          for(int i=0;i<n;i++)
             pg[i]=new PGStudent();
             sort_score(pg,n);
             System.out.println("\n----- Rank list------\n");
             for (int i=0;i<n;i++)
             {
                System.out.print((i+1)+".");
                pg[i].show();
             }
    }
}
