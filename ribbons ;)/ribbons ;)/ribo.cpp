#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
int main() {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *bit = NULL;
	al_init();
	display = al_create_display(500, 400);
	al_init_primitives_addon();
	al_clear_to_color(al_map_rgb(0, 150, 0));
	al_draw_circle(200, 300, 100, al_map_rgb(120, 0, 200), 5);
	al_draw_rectangle(50.0, 50.0, 200.0, 200.0, al_map_rgb(120, 0, 200), 5);
	al_flip_display();
	al_rest(20.0);
}

