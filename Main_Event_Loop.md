# 一、include
```
#include <glib.h>
```

# 二、Description

主事件循环管理GLib和GTK+应用程序的所有可用事件源。还可以使用 g_source_attach() 添加新的事件源类型。

为了允许在不同的线程中处理多个独立的源集，每个源都与 GMainContext 关联。GMainContext只能在一个线程中运行，但是可以将源添加到它并从其他线程中删除它。

每个事件源被分配一个优先级。默认的优先级 G_PRIORITY_DEFAULT 为0。小于0的值表示更高的优先级。大于0的值表示较低的优先级。来自高优先级源的事件总是在事件来自较低优先级源之前处理。

还可以添加空闲函数，并指定优先级。当没有更高优先级的事件准备处理时，就会运行这些操作。

GMainLoop数据类型表示一个主事件循环。使用g_main_loop_new()创建一个GMainLoop。在添加初始事件源之后，调用g_main_loop_run()。这将持续检查来自每个事件源的新事件并将它们分派给它们。最后，从一个源处理事件会导致调用g_main_loop_quit()来退出主循环，g_main_loop_run()返回。

## 2.1 Creating new source types

GMainLoop 功能的一个不同寻常的特性是，可以创建新的事件源类型，并将其用于构建事件源的内置类型。一个新的事件源类型用于处理GDK事件。一个新的源类型是由 GSource 结构的“派生”创建的。源的派生类型由具有 GSource 结构作为第一个元素的结构和特定于新源类型的其他元素表示。要创建新的源类型的实例，调用 g_source_new() 传递派生结构的大小和一个函数表。这些 GSourceFuncs 决定了新的源类型的行为。

新的源类型主要以两种方式与主上下文交互。它们在 GSourceFuncs 中的准备函数可以设置一个超时，以确定主循环在再次检查源之前休眠的最长时间。此外，或者也可以将文件描述符添加到使用 g_source_add_poll() 的主上下文检查的设置中。


## 2.2 Creating new source types 自定义主循环迭代。

GMainContext的单个迭代可以使用g_main_context_iteration()运行。在某些情况下，需要更详细地控制主循环工作的详细信息，例如，在将GMainLoop与外部主循环集成时。在这种情况下，可以直接调用g_main_context_iteration()的组件函数。这些函数是g_main_context_prepare()、g_main_context_query()、g_main_context_check()和g_main_context_dispatch()。


## 2.3 State of a Main Context

这些函数的操作可以从状态图中看到，如图所示。


在UNIX上，GLib mainloop与fork()不兼容。任何使用主循环的程序都必须从子程序中执行exec()或exit()，而不返回主循环。
