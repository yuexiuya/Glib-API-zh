/*
 * Generated by gdbus-codegen 2.40.2. DO NOT EDIT.
 *
 * The license of this code is the same as for the source it was derived from.
 */

#ifndef __BUILDING_H__
#define __BUILDING_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for com.joshua.Building.Test */

#define TYPE_TEST (test_get_type ())
#define TEST(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_TEST, Test))
#define IS_TEST(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_TEST))
#define TEST_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), TYPE_TEST, TestIface))

struct _Test;
typedef struct _Test Test;
typedef struct _TestIface TestIface;

struct _TestIface
{
  GTypeInterface parent_iface;


  gboolean (*handle_joshua_method) (
    Test *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_value);

  void (*joshua_signal) (
    Test *object,
    gint arg_status);

};

GType test_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *test_interface_info (void);
guint test_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void test_complete_joshua_method (
    Test *object,
    GDBusMethodInvocation *invocation,
    const gchar *reply);



/* D-Bus signal emissions functions: */
void test_emit_joshua_signal (
    Test *object,
    gint arg_status);



/* D-Bus method calls: */
void test_call_joshua_method (
    Test *proxy,
    const gchar *arg_value,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean test_call_joshua_method_finish (
    Test *proxy,
    gchar **out_reply,
    GAsyncResult *res,
    GError **error);

gboolean test_call_joshua_method_sync (
    Test *proxy,
    const gchar *arg_value,
    gchar **out_reply,
    GCancellable *cancellable,
    GError **error);



/* ---- */

#define TYPE_TEST_PROXY (test_proxy_get_type ())
#define TEST_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_TEST_PROXY, TestProxy))
#define TEST_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_TEST_PROXY, TestProxyClass))
#define TEST_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_TEST_PROXY, TestProxyClass))
#define IS_TEST_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_TEST_PROXY))
#define IS_TEST_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_TEST_PROXY))

typedef struct _TestProxy TestProxy;
typedef struct _TestProxyClass TestProxyClass;
typedef struct _TestProxyPrivate TestProxyPrivate;

struct _TestProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  TestProxyPrivate *priv;
};

struct _TestProxyClass
{
  GDBusProxyClass parent_class;
};

GType test_proxy_get_type (void) G_GNUC_CONST;

void test_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
Test *test_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
Test *test_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void test_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
Test *test_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
Test *test_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define TYPE_TEST_SKELETON (test_skeleton_get_type ())
#define TEST_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_TEST_SKELETON, TestSkeleton))
#define TEST_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_TEST_SKELETON, TestSkeletonClass))
#define TEST_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_TEST_SKELETON, TestSkeletonClass))
#define IS_TEST_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_TEST_SKELETON))
#define IS_TEST_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_TEST_SKELETON))

typedef struct _TestSkeleton TestSkeleton;
typedef struct _TestSkeletonClass TestSkeletonClass;
typedef struct _TestSkeletonPrivate TestSkeletonPrivate;

struct _TestSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  TestSkeletonPrivate *priv;
};

struct _TestSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType test_skeleton_get_type (void) G_GNUC_CONST;

Test *test_skeleton_new (void);


G_END_DECLS

#endif /* __BUILDING_H__ */
