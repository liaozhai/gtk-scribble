#include <gtk/gtk.h>

static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data) {
	g_print("delete event occurred\n");
	return FALSE;
}

static void destroy(GtkWidget *widget, gpointer data) {
	gtk_main_quit();
}

int main(int argc, char *argv[]) {
	GtkWidget *window;
	GtkWidget *label;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window, "delete-event", G_CALLBACK (delete_event), NULL);
	g_signal_connect(window, "destroy", G_CALLBACK (destroy), NULL);
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	gtk_widget_show(window);

	label = gtk_label_new("HELLO!");
	gtk_container_add(GTK_CONTAINER(window), label);
	gtk_widget_show(label);

	gtk_main();

	return 0;
}
