先做个简单的了解吧，实际上还用不到这么复杂的操作。

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

![image](https://github.com/yuexiuya/Glib-API-zh/blob/master/image/main_loop_state.png?raw=true)

在UNIX上，GLib mainloop与fork()不兼容。任何使用主循环的程序都必须从子程序中执行exec()或exit()，而不返回主循环。


## 2.4 Memory management of sources

对于传递给GSource的用户数据的内存管理有两种选择，可以将其传递给调用的回调函数。这些数据是在调用g_timeout_add()、g_timeout_add_full()、g_idle_add()等调用时提供的，通常使用g_source_set_callback()。该数据通常是“拥有”超时或空闲回调的对象，例如小部件或网络协议实现。在许多情况下，在这个拥有对象被销毁后调用回调函数是一个错误，因为这会导致释放内存的使用。

首选的选项是存储由函数(如g_timeout_add()或g_source_attach()等函数返回的源ID，并使用g_source_remove()来显式地从主上下文中删除该源。这确保了在对象还活着的情况下只能调用回调。

第二个选项是对回调中的对象进行强引用，并在回调的GDestroyNotify中释放它。这样可以确保在源完成之后，对象才能被保存，这将保证在最后一次调用它之后。GDestroyNotify是传递给GSource函数的“full”变体的另一个回调函数(例如，g_timeout_add_full())。当源代码最终完成时，它被调用，并被设计用于发布这样的引用。

第二种方法的一个重要警告是，如果在调用GSource之前停止主循环，它将无限期地保留对象，这可能是不可取的。
