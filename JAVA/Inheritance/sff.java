class Person
{
    String name;
    String gender;
    String address;
    int age;
    public Person(String name,String gender,String address,int age)
    {
        this.name=name;
        this.gender=gender;
        this.address=address;
        this.age=age;
    }
    public void displayPerson()
    {
        System.out.println("Name:"+name+"\nAge:"+age+"\nGender:"+gender+"\nAddress:"+address)
    }

}
class Employee extends Person
{
    int empid;
    String company_name;
    String qualification;
    int salary;
    public Employee(String name,String gender,String address,int age,int empid,String company_name,String qualification,int salary)
    {
        super(name,gender,address,age);
        this.empid=empid;
        this.company_name=company_name;
        this.qualification=qualification;
        this.salary=salary;
    }
    public void displayEmployee()
    {
        System.out.println("Employee Details:-\nEmployee id:"+empid+"\nCompany Name:"+company_name+"\nQualification:"+qualification+"\nSalary:"+salary);
    }
}
class Teacher extends Employee
{
    int teacherid;
    String subject;
    String department;
    public Teacher(String name,String gender,String address,int age,int empid,String company_name,String qualification,int salary,int teacherid,String subject,String department)
    {
        super(name,gender,address,age,101);
    }
}
