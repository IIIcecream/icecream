package test;

import main.ioc.Car;
import main.ioc.CustomService;
import main.ioc.UserServiceImpl;
import main.intf.UserService;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class UserServiceTest{
    @Test
    public void test1(){
        // 传统方式
        UserService usi = new UserServiceImpl();
        usi.setName("ahha");
        usi.print();
    }

    @Test
    public void test2()
    {
        // spring bean 方式
        // 创建工厂，加载核心配置文件
        ApplicationContext ac = new ClassPathXmlApplicationContext("main\\resources\\ApplicationContext.xml");

        // 从工厂中获取到对象
        UserService usi = (UserService)ac.getBean("UserService");

        // 调用对象的方法执行
        usi.print();
    }

    @Test
    public void test3()
    {
        // spring bean 方式
        // 创建工厂，加载核心配置文件
        ApplicationContext ac = new ClassPathXmlApplicationContext("main\\resources\\ApplicationContext.xml");

        // 从工厂中获取到对象
        CustomService cs = (CustomService)ac.getBean("CustomService");

        // 调用对象的方法执行
        cs.print();
    }

    @Test
    public void test4()
    {

        // spring bean 方式
        // 创建工厂，加载核心配置文件
        ApplicationContext ac = new ClassPathXmlApplicationContext("main\\resources\\ApplicationContext.xml");

        // 从工厂中获取到对象
        Car car = (Car)ac.getBean("Car");

        car.print();


    }
}
