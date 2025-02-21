import java.util.ArrayList;
import java.util.Scanner;
import java.util.Collections;
public class StudentName 
{
    public static void main(String[] args) 
    {
        ArrayList<String> names = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        int ch;
        do {
            System.out.println("\nMenu:");
            System.out.println("1. Add Name \n2. Remove Name \n3. Search for name\n4. Sort names\n5. Display Names\n6. Exit");
            System.out.print("Enter your choice: ");
            ch = sc.nextInt();
            sc.nextLine(); 
            switch (ch)
            {
                case 1:
                    System.out.print("Enter name to add: ");
                    String nameadd = sc.nextLine();
                    names.add(nameadd);
                    System.out.println(nameadd + "added.");
                    break;

                case 2:
                    System.out.print("Enter name to remove: ");
                    String Remove = sc.nextLine();
                    if (names.remove(Remove)) {
                        System.out.println(Remove + "removed.");
                    } else {
                        System.out.println(Remove + " not found in the list.");
                    }
                    break;
                case 3:
                    System.out.print("Enter name to search: ");
                    String s = sc.nextLine();
                    if (names.contains(s)) 
                    {
                        System.out.println(s + "is present in list.");
                    } 
                    else
                     {
                        System.out.println(s + " not found in the list.");
                    }
                    break;
                case 4:
                    System.out.println("Sorted Names:-")
                    Collections.sort(names);
                    for (String name : names) 
                        {
                        System.out.println(name);
                        };
                    break;
                case 5:
                    System.out.println("List of Names:");
                        for (String name : names) 
                        {
                            System.out.println(name);
                        }
                    break;

                case 6:
                    System.out.println("Exiting the program.");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }
        } while (ch!= 6);
        sc.close();
    }
}
//output
// Menu:
// 1. Add Name 
// 2. Remove Name 
// 3. Search for name
// 4. Sort names
// 5. Display Names
// 6. Exit
// Enter your choice: 1
// Enter name to add: John
// Johnadded.

// Menu:
// 1. Add Name 
// 2. Remove Name 
// 3. Search for name
// 4. Sort names
// 5. Display Names
// 6. Exit
// Enter your choice: 1
// Enter name to add: Sandra
// Sandraadded.

// Menu:
// 1. Add Name 
// 2. Remove Name 
// 3. Search for name
// 4. Sort names
// 5. Display Names
// 6. Exit
// Enter your choice: 1
// Enter name to add: Ann
// Annadded.

// Menu:
// 1. Add Name 
// 2. Remove Name 
// 3. Search for name
// 4. Sort names
// 5. Display Names
// 6. Exit
// Enter your choice: 5
// List of Names:
// John
// Sandra
// Ann

// Menu:
// 1. Add Name 
// 2. Remove Name 
// 3. Search for name
// 4. Sort names
// 5. Display Names
// 6. Exit
// Enter your choice: 3
// Enter name to search: Ann
// Annis present in list.

// Menu:
// 1. Add Name 
// 2. Remove Name 
// 3. Search for name
// 4. Sort names
// 5. Display Names
// 6. Exit
// Enter your choice: 2
// Enter name to remove: Ann
// Annremoved.

// Menu:
// 1. Add Name 
// 2. Remove Name 
// 3. Search for name
// 4. Sort names
// 5. Display Names
// 6. Exit
// Enter your choice: 5
// List of Names:
// John
// Sandra
