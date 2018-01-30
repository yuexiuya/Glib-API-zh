#include"Building.h"
#include"dbusServer.h"

static Test* skeleton=NULL;

static  gboolean on_handle_joshua_method(Test* skeleton,
        GDBusMethodInvocation *invocation,
        const gchar *greeting,
        gpointer data);

static gboolean emit_joshua_signal(gconstpointer p);

int main(int argc,char* argv[])
{
    char* s = "joshua";
    GMainLoop* loop = NULL;

    guint own_id =
        g_bus_own_name (G_BUS_TYPE_SESSION,
                "com.joshua.Building.Test",
                G_BUS_NAME_OWNER_FLAGS_NONE,
                gbus_acquired_handler,
                gbus_name_acquired_handler,
                gbus_name_lost_handler,
                (gpointer)s,
                NULL);

    /* * emit my signal1 every 1 second to trigger example communication */
    g_timeout_add(1000, (GSourceFunc)emit_joshua_signal, NULL);

    loop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(loop);

    g_bus_unown_name(own_id);
    return 0;
}

void gbus_acquired_handler(GDBusConnection *connection, const gchar *name, gpointer data)
{
    g_print(" %s [ START ]\n",__FUNCTION__);
    g_print(" name = %s, data = %s \n",name,data);
    GError *error = NULL;

    skeleton =  test_skeleton_new ();
    g_signal_connect(skeleton,"handle-joshua-method",G_CALLBACK(on_handle_joshua_method),NULL);

    g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON(skeleton), connection, "/com/joshua/Building/Test", &error);
    if(error != NULL){
        g_print("Error: Failed to export object. Reason: %s.\n", error->message);
        g_error_free(error);
    }
    g_print(" %s [ END ]\n",__FUNCTION__);
}

void gbus_name_acquired_handler(GDBusConnection *connection, const gchar *name, gpointer data)
{
    g_print(" %s \n",__FUNCTION__);
}

void gbus_name_lost_handler(GDBusConnection *connection, const gchar *name, gpointer data)
{
    g_print(" %s \n",__FUNCTION__);
}

static  gboolean on_handle_joshua_method(Test* skeleton,
        GDBusMethodInvocation *invocation,
        const gchar *greeting,
        gpointer data)
{
    g_print("Method call: %s\n", greeting);

    char* reply = "getSuccess";
    test_complete_joshua_method (skeleton,invocation,reply);

    return TRUE;
}

static gboolean emit_joshua_signal(gconstpointer p)
{
    g_print("emit_joshua_signal() is called.\n");
    gint status = 5;
    test_emit_joshua_signal (skeleton,status);
    return TRUE;
}
