https://developer.gnome.org/gobject/stable/api-index-full.html


## g_object_set

这里大多数都是用来get元素的属性，对于属性不知的元素，可以使用

gst-inspcet element名称来查看


```
void    g_object_set    (gpointer object,const gchar *first_property_name,...);
//创建一个gobject对象，并为其分配一些属性
//Parameters
//(1)object  对象
//(2)属性列表，应该以NULL为结尾

//一个例子
  /* create player */
  player = gst_element_factory_make ("oggvorbisplayer", "player");
  /* set the source audio file */
  g_object_set (player, "location", "helloworld.ogg", NULL);
  /* start playback */
//上述的例子中，没有严格的传参，因为player是一个GstElement的类型。这里不妨先做个假设，这个gobject的类型放的很宽，大多数类型都可以适配。
```

## g_object_get


```
void g_object_get (gpointer object,
				const gchar *first_property_name,
					       ...)
//(1)object  对象
//(2)属性列表，应该以NULL为结尾

//例子
  g_object_get (G_OBJECT (element), "name", &name, NULL);
```


## g_signal_connect ()

Memory management of signal handlers - 信号处理器 的内存分配



```
#define             g_signal_connect(instance, detailed_signal, c_handler, data)
// 绑定 instance 的 detailed_signal -> c_handler( data 作为入参)
//Parameters
//(1)instance ： 信号的所有者
//(2)detailed_signal : 信号
//(3)c_handler : G_CALLBACK
//(4)data ： c_handler 的入参

//Returns
//the handler ID, of type gulong (always greater than 0 for successful connections)
```
