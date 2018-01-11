https://developer.gnome.org/glib/unstable/api-index-full.html

## g_get_current_time()

```
void
g_get_current_time (GTimeVal *result);
//类似于gettimeofday
//Parameters
//(1)result : 得到的时间结果存在里面

//配合GST_TIMEVAL_TO_TIME宏的使用
g_get_current_time(&tfnow);
tfafter = GST_TIMEVAL_TO_TIME(tfnow);
```

```
typedef struct _GTimeVal                GTimeVal;

struct _GTimeVal
{
  glong tv_sec;
  glong tv_usec;
};

```
## g_get_real_time ()
//没获得想要的结果
```
gint64
g_get_real_time (void);
//功能等于g_get_current_time，但是返回值更直接
```

## g_object_set()


```

```


## g_main_loop_new()

```
GMainLoop *
g_main_loop_new (GMainContext *context,
                 gboolean is_running);

//Creates a new GMainLoop structure.

//Parameters
//(1) context : a GMainContext, NULL = default context中去
//(2) is_running : TRUE = g_main_loop_run; false = not run;

//Return
a new GMainLoop.

//一个例子

g_main_loop_new (NULL, FALSE);

```


## g_main_loop_ref ()

```
GMainLoop *
g_main_loop_ref (GMainLoop *loop);

//Increases the reference count on a GMainLoop object by one.
//Parameters
//(1) loop : a GMainLoop
//Returns
//GMainLoop* : loop

```

## g_main_loop_unref ()

```
void
g_main_loop_unref (GMainLoop *loop);
//Decreases the reference count on a GMainLoop object by one. If the result is zero, free the loop and free all associated memory.
//Parameters
//(1) loop : a GMainLoop
```


## g_main_loop_run ()

```
void
g_main_loop_run (GMainLoop *loop);
//启动一个主事件循环，直到调用 g_main_loop_quit()退出；
//Parameters
//(1) loop : 循环

```


## g_main_loop_quit ()

```
void
g_main_loop_quit (GMainLoop *loop);
//停止一个循环，g_main_loop_run()将return
//在quit之前发出的信息，依然会生效
//Parameters
//(1) loop : a GMainLoop
```
