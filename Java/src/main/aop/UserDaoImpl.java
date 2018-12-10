package main.aop;

/**
 * brief:    面相切片aop
 * author:   tangw-b 2018/09/27 20:58
 * param:    无
 * return:
 */

public class UserDaoImpl implements UserDao {
    @Override
    public void save() {
        System.out.println("保存用户。。。");
    }

    @Override
    public void update() {
        System.out.println("更新用户。。。");
    }
}
