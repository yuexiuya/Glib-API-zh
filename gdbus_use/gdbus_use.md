# 一、gdbus 的概述

参考网址(https://www.freedesktop.org/software/gstreamer-sdk/data/docs/latest/gio/gio-Owning-Bus-Names.html#g-bus-own-name)





# 二、gdbus-codegen
  用于将 .xml -> .c .h 文件，自动将 xml 内的接口转换成 编码 gdbus 的 server、client端，简化代码量。

## 2.1 gdbus-codegen cmd 的介绍

```
Usage: gdbus-codegen [options]

Options:
  -h, --help            show this help message and exit
  --xml-files=FILE      D-Bus introspection XML file
  --interface-prefix=PREFIX
  //接口名的前缀，可以帮你省去xml中interface的名字，使得代码可读性增加
                        String to strip from D-Bus interface names for code
                        and docs
  --c-namespace=NAMESPACE
                        The namespace to use for generated C code
  --c-generate-object-manager
                        Generate a GDBusObjectManagerClient subclass when
                        generating C code
  --generate-c-code=OUTFILES
                        Generate C code in OUTFILES.[ch]
    //指定生成.c,.h 文件的名字
  --generate-docbook=OUTFILES
                        Generate Docbook in OUTFILES-org.Project.IFace.xml
  --annotate=WHAT KEY VALUE
                        Add annotation (may be used several times)
```

## 2.2 常用的 cmd

```
gdbus-codegen --generate-c-code=Building --interface-prefix com.joshua.Building Building.xml
```

# 三、gdbus 的注册流程(服务端 \ 客户端)

## 3.1 流程说明

## 3.2 api 的使用说明

### g_bus_own_name ()

```
guint               g_bus_own_name                      (GBusType bus_type,
                                                         const gchar *name,
                                                         GBusNameOwnerFlags flags,
                                                         GBusAcquiredCallback bus_acquired_handler,
                                                         GBusNameAcquiredCallback name_acquired_handler,
                                                         GBusNameLostCallback name_lost_handler,
                                                         gpointer user_data,
                                                         GDestroyNotify user_data_free_func);
//把 name 用 flags 的形式 注册到 bus_type 上，注册时会调用 name_acquired_handler，失去连接是会调用 name_lost_handler。
//关于 callback 线程的说明，目前拿捏不准--Callbacks will be invoked in the thread-default main loop of the thread you are calling this function from.
//你在使用这个function，必然会获得以下三种回调中的一种
//(1)name_lost_handler with a NULL connection (if a connection to the bus can't be made).
//(2)bus_acquired_handler then name_lost_handler (if the name can't be obtained)
//(3)bus_acquired_handler then name_acquired_handler (if the name was obtained).
//当你做完你所需要的工作之后，调用 g_bus_own_name() 释放

//Parameters
//(1)bus_type : session bus or system bus ??
//(2)name : dbus server's adddress
//(3)flags : A set of flags from the GBusNameOwnerFlags enumeration.
//(4)bus_acquired_handler : Handler to invoke when connected to the bus of type bus_type or NULL. [allow-none]
//(5)name_acquired_handler : Handler to invoke when name is acquired or NULL. [allow-none]
//(6)name_lost_handler :  Handler to invoke when name is acquired or NULL. [allow-none]
//(7)user_data :  Handler to invoke when name is acquired or NULL. [allow-none]
//(8)user_data_free_func :  一般为NULL
//Returns
//An identifier (never 0) that an be used with g_bus_unown_name() to stop owning the name.
```

## 3.3 demo测试程序
