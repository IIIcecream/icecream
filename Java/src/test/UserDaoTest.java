package test;

import main.aop.MyUserDaoUtils;
import main.aop.UserDao;
import main.aop.UserDaoImpl;
import org.junit.Test;

/**
 * brief:    aop测试
 * author:   tangw-b 2018/09/27 21:02
 * param:    无
 * return:
 */

public class UserDaoTest {

    @Test
    public void test1() {
        UserDao ud = new UserDaoImpl();
        ud.save();
        ud.update();

        //使用工具类，获取代理对象
        UserDao proxy = MyUserDaoUtils.getProxy(ud);
        proxy.save();
        proxy.update();
    }
}
