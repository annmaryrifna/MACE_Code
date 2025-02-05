class CPU
{
    int price;
    public CPU(int price)
    {
        this.price=price;
    }
    public void displayCPUPrice()
    {
        System.out.println("CPU price:"+price);
    }
    class Processor
    {
         int no_cores;
        String manufacture;
        public Processor(int c,String m)
        {
            no_cores=c;
            manufacture=m;
        }
        public void displayProcessor()
        {
         System.out.println("NO. of cores:"+no_cores+"\nManufacture:"+manufacture);   
        }
    }
    static class RAM
    {
        int memory;
        String manufacture;
        public RAM(int me,String m)
        {
            memory=me;
            manufacture=m;
        }
        public void displayRAM()
        {
         System.out.println("Memory:"+memory+"\nManufacture:"+manufacture);   
        }
    }
}
public class CPUDemo
{
    public static void main(String []arg)
    {
        CPU c=new CPU(10000);
        CPU.Processor p=c.new Processor(2,"xyz");
        CPU.RAM r= new CPU.RAM(4,"abc");
        System.out.println("CPU features:")
        c.displayCPUPrice();
        p.displayProcessor();
        r.displayRAM();
    }
}
