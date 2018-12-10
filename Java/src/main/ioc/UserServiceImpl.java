package main.ioc;

import main.intf.UserService;

public class UserServiceImpl implements UserService{
    private String name;
    public void setName(String name) { this.name = name; }
    public void print()
    {
        System.out.println("hello " + name);
    }
}
