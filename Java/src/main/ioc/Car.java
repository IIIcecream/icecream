package main.ioc;

/**
 * 构造方法注入
 */
public class Car {
    private int price;
    private String name;

    public Car(String name, int price)
    {
        this.price = price;
        this.name = name;
    }

    public void print()
    {
        System.out.println(name + price);
    }
}
