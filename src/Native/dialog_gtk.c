#include <errno.h>
#include <gtk/gtk.h>

void revery_alert_gtk(void *pWin, const char *szMessage) {
  GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;
  GtkWidget *dialog;
  dialog = gtk_message_dialog_new(NULL, flags, GTK_MESSAGE_ERROR,
                                  GTK_BUTTONS_CLOSE, "Error reading “%s”: %s",
                                  "filename", g_strerror(errno));
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}
