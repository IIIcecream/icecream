package main.aop;

/**
 * brief:    CGlib方式生成代理对象
 * author:   tangw-b 2018/09/28 19:32
 * param:    无
 */

public class BookDaoImpl {
    public void save(){
        System.out.println("save");
    }
    public void update()
    {
        System.out.println("update");
    }
}
