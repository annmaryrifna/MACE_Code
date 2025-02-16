import java.util.Scanner;
interface Showable {
    public void show();
}

class Person implements Showable {
    String name, gender;
    int phoneno;

    Person(String name, String gender, int phoneno) {
        this.name = name;
        this.gender = gender;
        this.phoneno = phoneno;
    }

    public void show() {
        System.out.println("Student Name:" + name + "\nGender:" + gender + "\nPhone No:" + phoneno);
    }
}

class Student extends Person implements Showable {
    String course;
    int score;

    Student(String name, String gender, int phoneno, String course, int score) {
        super(name, gender, phoneno);
        this.course = course;
        this.score = score;
    }

    public void show() {
        super.show();
        System.out.println("Course: " + course);
        System.out.println("Score: " + score);
    }
}

class PGStudent extends Student implements Showable 
{
    String researchArea, guide;
    PGStudent(String name, String gender, int phoneno, String course, int score, String researchArea, String guide) {
        super(name, gender, phoneno, course, score);
        this.researchArea = researchArea;
        this.guide = guide;
    }

    public void show() {
        super.show();
        System.out.println("Research Area: " + researchArea);
        System.out.println("Guide: " + guide);
        System.out.println();
    }
}

public class StudentRank 
{
    public  static void sort_score(PGStudent pg[], int n) 
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++)
             {
                if (pg[i].score < pg[j].score) 
                {
                    PGStudent temp = pg[i];
                    pg[i] = pg[j];
                    pg[j] = temp;
                }
            }
        }
    }
    public static void SortResearchArea(PGStudent[] arr) 
    {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) 
        {
            for (int j = 0; j < n - i - 1; j++) 
            {
                if (arr[j].researchArea.compareToIgnoreCase(arr[j + 1].researchArea) > 0)
                 {
                    PGStudent temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    public static void main(String arg[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter no of student:");
        int n = sc.nextInt();
        sc.nextLine();
        PGStudent pg[] = new PGStudent[n];
        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details for PGStudent " + (i + 1) + ":");

            System.out.print("Name: ");
            String name = sc.nextLine();

            System.out.print("Gender: ");
            String gender = sc.nextLine();

            System.out.print("Phone No: ");
            int phoneno = sc.nextInt();
            sc.nextLine(); 

            System.out.print("Course: ");
            String course = sc.nextLine();

            System.out.print("Score: ");
            int score = sc.nextInt();
            sc.nextLine(); 

            System.out.print("Research Area: ");
            String researchArea = sc.nextLine();

            System.out.print("Guide: ");
            String guide = sc.nextLine();

            pg[i] = new PGStudent(name, gender, phoneno, course, score, researchArea, guide);
        }
        sort_score(pg, n);
        System.out.println("\n----- Rank list------\n");
        for (int i = 0; i < n; i++) {
            System.out.print((i + 1) + ".");
            pg[i].show();
        }
       SortResearchArea(pg);

        System.out.println("\n--- Sorted by Research Area  ---\n");
        for (int i = 0; i < n; i++) {
            System.out.print((i + 1) + ". ");
            pg[i].show();
        }
        sc.close();
    }
   
} 

----------output---------
// Enter no. of students:
// 2

// Enter details for PGStudent 1:
// Name: Sam
// Gender: M
// Phone No: 97538302
// Course: maths
// Score: 90
// Research Area: Statics
// Guide: Ninny

// Enter details for PGStudent 2:
// Name: Joy
// Gender: M
// Phone No: 987654323
// Course: Mca
// Score: 80
// Research Area: AI
// Guide: Rosy

// ----- Rank list------

// 1.Student Name:Sam
// Gender:M
// Phone No:97538302
// Course: maths
// Score: 90
// Research Area: Statics
// Guide: Ninny

// 2.Student Name:Joy
// Gender:M
// Phone No:987654323
// Course: Mca
// Score: 80
// Research Area: AI
// Guide: Rosy

// --- Sorted by Research Area  ---
// 1. Student Name:Joy
// Gender:M
// Phone No:987654323
// Course: Mca
// Score: 80
// Research Area: AI
// Guide: Rosy

// 2. Student Name:Sam
// Gender:M
// Phone No:97538302
// Course: maths
// Score: 90
// Research Area: Statics
// Guide: Ninny
