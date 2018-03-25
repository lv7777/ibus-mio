// Copyright [2018] <lv7777>

#include<gtk/gtk.h>
#include<stdlib.h>

void button_was_clicked(GtkWidget *widget, gpointer data) {
g_print("HELLO!");
}

gint gclose(GtkWidget *widget, gpointer gdata) {
g_print("Quiting");
gtk_main_quit();

return(FALSE);
}

int main(int argc, char **argv) {
GtkWidget *window;
GtkWidget *button;

gtk_set_locale();

gtk_init(&argc, &argv);

gtk_rc_parse("./gtkrc");

window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

gtk_signal_connect(GTK_OBJECT(window),
 "delete_event", GTK_SIGNAL_FUNC(gclose),
  NULL);

gtk_container_border_width(GTK_CONTAINER(window), 15);

button = gtk_button_new_with_label("hello");

g_signal_connect(GTK_OBJECT(button),
 "clicked",
 GTK_SIGNAL_FUNC(button_was_clicked),
 NULL);

gtk_container_add(GTK_CONTAINER(window), button);

gtk_widget_show(button);

gtk_widget_show(window);

gtk_main();

return 0;
}
