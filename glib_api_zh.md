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
