#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
int main() {
	
	al_init();
	al_init_font_addon();//sets up font addon
	al_init_primitives_addon();
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *bit = NULL;
	ALLEGRO_FONT* font = al_create_builtin_font();
	display = al_create_display(500, 400);
	
	al_clear_to_color(al_map_rgb(100, 100, 100));
	
	al_draw_filled_rectangle(100.0, 100.0, 400.0, 300.0, al_map_rgb(0, 150, 0));
	al_draw_rectangle(100.0, 100.0, 400.0, 300.0, al_map_rgb(0, 100, 0),5);
	al_draw_text(font, al_map_rgb(255, 255, 255), 250, 185, ALLEGRO_ALIGN_CENTER, "278 Northfeild/Quebec");
	al_flip_display();
	al_rest(30.0);
}

