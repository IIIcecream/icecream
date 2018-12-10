package main.aop;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

/**
 * brief:    jdk动态代理对象（有接口）
 * author:   tangw-b 2018/09/27 21:08
 * param:    无
 */

public class MyUserDaoUtils {
    private UserDao ud;

    public static UserDao getProxy(final UserDao ud)
    {
        //生成代理对象
        UserDao proxy = (UserDao)Proxy.newProxyInstance(ud.getClass().getClassLoader(), ud.getClass().getInterfaces(), new InvocationHandler() {
            // 只要代理对象方法被调用，invoke就会被执行一次
            @Override
            // proxy 当前生成的代理对象
            // method 当前调用代理对象使用的方法
            // args 调用方法的参数
            public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {

                // 此处前后就可以干一些自己的事情
                if(method.getName().equals("****"))
                {

                }

                //让UserDao类的方法正常执行
                return method.invoke(ud, args);
            }
        });
        return proxy;
    }
}
