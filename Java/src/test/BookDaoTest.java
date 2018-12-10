package test;

import main.aop.BookDaoImpl;
import main.aop.MyCGLibUtils;

/**
 * brief:    CGlib代理测试
 * author:   tangw-b 2018/09/28 19:42
 * param:    无
 */

public class BookDaoTest {
    BookDaoImpl bd = MyCGLibUtils.getProxy();
    // ?????
    //bd.save();
    //bd.update();
}
