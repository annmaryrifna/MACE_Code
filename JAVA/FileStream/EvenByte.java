import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
public class EvenByte 
{
    public static void main(String[] args) 
    {
        int[] numbers = {10, 15, 20, 25, 30, 35, 40, 45, 50}; 
       
        try (FileOutputStream fos = new FileOutputStream("even_numbers.dat")) 
        {
            for (int num : numbers) 
            {
                if (num % 2 == 0) 
                {

                    fos.write(num); 
                }
            }
            System.out.println("Even numbers written to file successfully.");
        } catch (IOException e) 
        {
            System.out.println("Error writing to file: " + e.getMessage());
        }

        try (FileInputStream fis = new FileInputStream("even_numbers.dat"))
         {
            System.out.println("Even numbers retrieved from file:");
            int num;
            while ((num = fis.read()) != -1) 
            {
                System.out.print(num + "\n");
            }
        } catch (IOException e) 
        {
            System.out.println("Error reading from file: " + e.getMessage());
        }
    }
}
