#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
int main() {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *bit = NULL;
	al_init();
	display = al_create_display(500, 400);
	al_init_primitives_addon();
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_filled_circle(250, 200, 50, al_map_rgb(210, 105, 30) );
	al_draw_filled_triangle(300.0, 200.0, 200.0, 200.0, 250.0, 400.0, al_map_rgb(210, 180, 140) );
	al_flip_display();
	al_rest(20.0);
}

