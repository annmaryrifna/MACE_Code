import java.util.ArrayList;
import java.util.Scanner;
import java.util.Collections;
import java.util.Comparator;

class Product
  {
     String name;
     double price;

    public Product(String name, double price) 
    {
        this.name = name;
        this.price = price;
    }

    public String getName() 
    {
        return name;
    }
    @Override
    public String toString() 
    {
        return "Product:{name='" + name + "', price=" + price + "}";
    }
}
public class ProductDetails
 {
    public static void main(String[] args) {
        ArrayList<Product> products = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        int ch;
        do {
            System.out.println("\nMenu:");
            System.out.println("1. Add product\n2. Sort product by name\n3. Display products\n4. Exit");
            System.out.print("Enter your choice: ");
            ch = sc.nextInt();
            sc.nextLine();
            switch (ch) {
                case 1:
                    System.out.print("Enter product name: ");
                    String name = sc.nextLine();
                    System.out.print("Enter product price: ");
                    double price = sc.nextDouble();
                    products.add(new Product(name, price));
                    System.out.println("Product added .");
                    break;
                case 2:
                    Collections.sort(products, Comparator.comparing(Product::getName));
                    System.out.println("Products sorted by name.");
                    for (Product product : products) {
                        System.out.println(product);
                    }
                    break;
                case 3:
                    System.out.println("List of products:");
                    for (Product product : products) {
                        System.out.println(product);
                    }
                    break;
                case 4:
                    System.out.println("Exiting the program.");
                    break;
                default:
                    System.out.println("Invalid choice!");
            }
        } while (ch != 4);
        sc.close();
    }
}
//output
// Menu:
// 1. Add product
// 2. Sort product by name
// 3. Display products
// 4. Exit
// Enter your choice: 1
// Enter product name: milk
// Enter product price: 28
// Product added .

// Menu:
// 1. Add product
// 2. Sort product by name
// 3. Display products
// 4. Exit
// Enter your choice: 1
// Enter product name: butter
// Enter product price: 120
// Product added.

// Menu:
// 1. Add product
// 2. Sort product by name
// 3. Display products
// 4. Exit
// Enter your choice: 1
// Enter product name: cheese
// Enter product price: 180
// Product added .

// Menu:
// 1. Add product
// 2. Sort product by name
// 3. Display products
// 4. Exit
// Enter your choice: 2
// Products sorted by name.
// Product:{name='butter', price=120.0}
// Product:{name='cheese', price=180.0}
// Product:{name='milk', price=28.0}

// Menu:
// 1. Add product
// 2. Sort product by name
// 3. Display products
// 4. Exit
// Enter your choice: 3
// List of products:
// Product:{name='butter', price=120.0}
// Product:{name='cheese', price=180.0}
// Product:{name='milk', price=28.0}
