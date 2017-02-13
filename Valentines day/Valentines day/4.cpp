#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
int main() {

	al_init();
	al_init_image_addon();
	al_init_font_addon();//sets up font addon
	al_init_primitives_addon();
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *bit = NULL;
	ALLEGRO_BITMAP *Picture1 = NULL;
	ALLEGRO_FONT* font = al_create_builtin_font();
	display = al_create_display(500, 400);

	al_clear_to_color(al_map_rgb(100, 100, 100));

	al_draw_filled_rectangle(100.0, 100.0, 400.0, 300.0, al_map_rgb(150, 0, 0));
	al_draw_rectangle(100.0, 100.0, 400.0, 300.0, al_map_rgb(100, 0, 0), 5);
	
	Picture1 = al_load_bitmap("bee.jpg");
	al_draw_text(font, al_map_rgb(255, 255, 255), 250, 185, ALLEGRO_ALIGN_CENTER, "Bee my valentine...");
	al_draw_bitmap(Picture1, 195, 200, 0);
	al_flip_display();
	al_flip_display();
	al_rest(30.0);
}

