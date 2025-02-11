import java.util.Scanner;
class Person
{
    String name;
    String gender;
    String address;
    int age;
    public Person(String name, String gender, String address, int age)
    {
        this.name = name;
        this.gender = gender;
        this.address = address;
        this.age = age;
    }

    public void displayPerson()
    {
        System.out.println("Name: " + name + "\nAge: " + age + "\nGender: " + gender + "\nAddress: " + address);
    }
}

class Employee extends Person
{
    int empid;
    String company_name;
    String qualification;
    int salary;
    public Employee(String name, String gender, String address, int age, int empid, String company_name,String qualification, int salary)
    {
        super(name, gender, address, age);
        this.empid = empid;
        this.company_name = company_name;
        this.qualification = qualification;
        this.salary = salary;
    }
    public void displayEmployee()
    {
        super.displayPerson();
        System.out.println("\nEmployee ID: " + empid + "\nCompany Name: " + company_name+ "\nQualification: " + qualification + "\nSalary: " + salary);
    }
}
class Teacher extends Employee 
{
    int teacherid;
    String subject;
    String department;
    public Teacher(String name, String gender, String address, int age, int empid, String company_name,String qualification, int salary, int teacherid, String subject, String department) 
    {
        super(name, gender, address, age, empid, company_name, qualification, salary);
        this.teacherid = teacherid;
        this.subject = subject;
        this.department = department;
    }
    public void displayTeacher()
    {
         super.displayEmployee();
        System.out.println("\nTeacher ID: " + teacherid + "\nSubject: " + subject + "\nDepartment: " + department);
    }
}
class Multilevel
    {
    public static void main(String[] arg) 
        {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of teachers: ");
        int n = sc.nextInt();
        Teacher[] t = new Teacher[n];
        for (int i = 0; i < n; i++) 
            {
            System.out.println("\nEnter details for Teacher " + (i + 1) + ":");
            System.out.print("Enter Name: ");
            sc.nextLine(); 
            String name = sc.nextLine();
            System.out.print("Enter Gender: ");
            String gender = sc.nextLine();
            System.out.print("Enter Address: ");
            String address = sc.nextLine();
            System.out.print("Enter Age: ");
            int age = sc.nextInt();
            System.out.print("Enter Employee ID: ");
            int empid = sc.nextInt();
            sc.nextLine();
            System.out.print("Enter Company Name: ");
            String company_name = sc.nextLine();
            System.out.print("Enter Qualification: ");
            String qualification = sc.nextLine();
            System.out.print("Enter Salary: ");
            int salary = sc.nextInt();
            System.out.print("Enter Teacher ID: ");
            int teacherid = sc.nextInt();
            sc.nextLine(); 
            System.out.print("Enter Subject: ");
            String subject = sc.nextLine();
            System.out.print("Enter Department: ");
            String department = sc.nextLine();
            t[i] = new Teacher(name, gender, address, age, empid, company_name, qualification, salary, teacherid, subject, department);
        }
        for (int i = 0; i < n; i++) {
            System.out.println("\nDisplaying Teacher " + (i + 1) + " details:");
            t[i].displayTeacher();
        }
    }
}
