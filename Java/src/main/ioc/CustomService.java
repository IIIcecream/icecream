package main.ioc;

import org.springframework.beans.factory.annotation.Autowired;

public class CustomService {
    /**
     * 依赖注入对象
     */
    private CustomDao cd;

    public void setCustomDao(CustomDao cd)
    {
        this.cd = cd;
    }

    public void print()
    {
        System.out.println("I'm CustomService\n");
        cd.print();
    }
}
