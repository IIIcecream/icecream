package main.aop;

/**
 * brief:    aop
 * author:   tangw-b 2018/09/28 20:16
 * param:    无
 */

public class CustomerImpl implements Customer {
    @Override
    public void save() {
        System.out.println("保存");
    }

    @Override
    public void update() {
        System.out.println("修改");
    }
}
