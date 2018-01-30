#include "dbusClient.h"

static gboolean joshua_signal_handle(Test* object,gint status,gpointer user_data);

int main(int argc, char *argv[])
{
    Test *proxy=NULL;
    GError *error = NULL;
    GMainLoop* loop = NULL;

    proxy = test_proxy_new_for_bus_sync (
            G_BUS_TYPE_SESSION,
            G_DBUS_PROXY_FLAGS_NONE,
            "com.joshua.Building.Test",
            "/com/joshua/Building/Test",
            NULL,
            &error);

    if(0 == proxy)
    {
        g_print("InitDBusCommunication: Failed to create proxy. Reason: %s.\n", error->message);
    }

    g_signal_connect(proxy,"joshua-signal",G_CALLBACK(joshua_signal_handle),NULL);

    char *reply = NULL;
    test_call_joshua_method_sync(proxy, "hello world", &reply,NULL, &error);
    g_print("sync reply = %s\n",reply);

    loop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(loop);

    g_object_unref(proxy);
    return 0;
}

static gboolean joshua_signal_handle(Test* object,gint status,gpointer user_data)
{
    g_print("signal received %d\n",status);
    return TRUE;
}
