import java.io.*;
import java.util.Scanner;

public class ConsoleTextToFile
 {
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        try (FileWriter writer = new FileWriter("output.txt")) 
        {
            System.out.println("Enter text to write to file end by stop:");
            String line;

            while (!(line = sc.nextLine()).equalsIgnoreCase("stop")) {
                writer.write(line + "\n");  
            }

            System.out.println("Text written to file successfully.");

        } catch (IOException e) {
            System.out.println("Error writing to file: " + e.getMessage());
        }

        System.out.println("-----Content of the file-----");
        try (FileReader reader = new FileReader("output.txt")) {
            int ch;
            while ((ch = reader.read()) != -1) {
                System.out.print((char) ch);
            }
        } catch (IOException e) {
            System.out.println("Error reading from file: " + e.getMessage());
        }

        sc.close();
    }
}
