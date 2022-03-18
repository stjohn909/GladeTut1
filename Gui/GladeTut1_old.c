#include <stdlib.h>
#include <inttypes.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <math.h>
#include <sys/time.h>



// Make them global

GtkWidget   *cont;
GtkWidget   *fixed;
GtkWidget   *button;
GtkWidget   *label;
GtkWidget   *draw;
GtkBuilder  *builder; 



gfloat graph_function (gfloat x)
{
    struct timeval spec;
    gettimeofday(&spec, NULL);
    //x+=spec.tv_usec;

    return sin(x * 10) * 100 ;
}

void on_button1_clicked (GtkButton *button) {
    gtk_label_set_text (GTK_LABEL(label), (const gchar* ) "Hello World");
	printf("Hello World!\n");
    
}


gboolean on_draw (GtkWidget *widget, cairo_t *cr, gpointer data)
{
    guint width, height;
    GdkRGBA color;
    GtkStyleContext *context;
    gdouble dx = 5.0, dy = 5.0; // Pixels between each point
    gdouble i, clip_x1 = 0.0, clip_y1 = 0.0, clip_x2 = width, clip_y2 = height;

    context = gtk_widget_get_style_context (widget);

    width = gtk_widget_get_allocated_width (widget);
    height = gtk_widget_get_allocated_height (widget);

    gtk_render_background (context, cr, 0, 0, width, height);
    /* Draw on a black background */
    cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
    cairo_paint (cr);

    /* Change the transformation matrix */
    //cairo_translate (cr, width / 2, height / 2);
    //cairo_scale (cr, 1.0, 1.0);  // Original example used defines for these.

     /* Draws x and y axis */

    cairo_translate (cr, 0, height / 2); // offset transform to mid-screen
    cairo_move_to (cr, clip_x1, 0.0);
    cairo_line_to (cr, clip_x2, 0.0);
    cairo_move_to (cr, 0.0, clip_y1);
    cairo_line_to (cr, 0.0, clip_y2);
    cairo_stroke (cr);

    for (i = 0; i < width; i += dx)
        cairo_line_to (cr, i, graph_function (i));

    /* Draw the curve */
    cairo_set_source_rgba (cr, 1, 0.2, 0.2, 0.6);
    cairo_stroke (cr);

    cairo_arc (cr,
                width / 2.0, height / 2.0,
                MIN (width, height) / 2.0,
                0, 2 * G_PI);

    gtk_style_context_get_color (context,
                                gtk_style_context_get_state (context),
                                &color);
    gdk_cairo_set_source_rgba (cr, &color);

    //cairo_stroke (cr);

    return FALSE;
}

int main(int argc, char *argv[]) {

gtk_init(&argc, &argv); // init Gtk

//---------------------------------------------------------------------
// establish contact with xml code used to adjust widget settings
//---------------------------------------------------------------------

builder = gtk_builder_new_from_file ("GladeTut1.glade");

gtk_builder_connect_signals(builder, NULL);

cont = GTK_WIDGET(gtk_builder_get_object(builder, "cont"));
g_signal_connect(cont, "destroy", G_CALLBACK(gtk_main_quit), NULL);

fixed = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
button = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
label = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));
draw = GTK_WIDGET(gtk_builder_get_object(builder, "draw1"));

gtk_widget_show(cont);

g_signal_connect (draw,"draw1", G_CALLBACK (on_draw), NULL);

gtk_main();

return EXIT_SUCCESS;
}
