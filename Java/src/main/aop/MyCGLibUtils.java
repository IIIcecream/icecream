package main.aop;

import org.springframework.cglib.proxy.Enhancer;
import org.springframework.cglib.proxy.MethodInterceptor;
import org.springframework.cglib.proxy.MethodProxy;

import java.lang.reflect.Method;

/**
 * brief:    CGlib方式代理对象创建（没有接口）
 * author:   tangw-b 2018/09/28 19:33
 * param:    无
 */

public class MyCGLibUtils {
    public static BookDaoImpl getProxy(){
        Enhancer enhancer = new Enhancer();
        //设置父类
        enhancer.setSuperclass(BookDaoImpl.class);

        //设置回调函数
        enhancer.setCallback(new MethodInterceptor() {
            @Override
            public Object intercept(Object o, Method method, Object[] args, MethodProxy methodProxy) throws Throwable {
                System.out.println("回调");
                return methodProxy.invokeSuper(o, args);
            }
        });

        //生成代理对象
        BookDaoImpl proxy = (BookDaoImpl)enhancer.create();
        return proxy;
    }
}
