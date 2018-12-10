package test;

import main.aop.CustomerImpl;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import javax.annotation.Resource;

/**
 * brief:    aop测试
 * author:   tangw-b 2018/09/28 20:18
 * param:    无
 */

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("classpath:main/resources/ApplicationContext.xml")

public class CustomerAOPTest {

    @Resource(name="customerImpl")
    private CustomerImpl ci;

    @Test
    public void run1()
    {
        ci.save();
        ci.update();
    }
}
