class Animal
{
    private String species;
    int age;
    float weight;
    protected String color;
    public Animal(String species,int age,float weight,String color)
    {
        this.species=species;
        this.age=age;
        this.weight=weight;
        this.color=color;
    }
    public void displayAnimal()
    {
        System.out.println(species+" "+age+" "+weight+" "+color);
    }
}
class Dog extends Animal
{
    String name;
    String owner;
    public Dog(String species,int age,float weight,String color,String name,String owner)
    {
        super(species,age,weight,color);
        this.name=name;
        this.owner=owner;
    }
    public void displayDog()
    {
        System.out.println(name+" is owned by "+owner);
    }
}
class Cat extends Animal
{
    int tailLength;
    String eyeColor;
    String name;
    public Cat(String species,int age,float weight,String color,int tailLength,String eyeColor,String name)
    {
        super(species,age,weight,color);
        this.tailLength=tailLength;
        this.eyeColor=eyeColor;
        this.name=name;
    }
    public void displayCat()
    {
        System.out.println(name+" has "+eyeColor+"color eye with "+tailLength+"m taillength.");
    }
}
class SingleDemo
{
    public static void main(String []arg)
    {
        Dog d=new Dog("Mammal",5,30,"brown","brunney","Ann");
        Cat c =new Cat("Mammal",2,10,"white",15,"blue","kitty");
        d.displayAnimal();
        d.displayDog();
        c.displayAnimal();
        c.displayCat();
    }
}
