#ifndef __GDBUS_SERVER_H_
#define __GDBUS_SERVER_H_

#include<stdio.h>
#include<gio/gio.h>
#include<glib.h>
#include<assert.h>

void gbus_acquired_handler (GDBusConnection *connection,
                                      const gchar     *name,
                                      gpointer         data);

void gbus_name_acquired_handler (GDBusConnection *connection,
                                          const gchar     *name,
                                          gpointer         data);

void gbus_name_lost_handler(GDBusConnection *connection,
                                      const gchar     *name,
                                      gpointer         data);
#endif
