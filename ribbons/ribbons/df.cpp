#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
int main() {
	const float FPS = 100;
	const int SCREEN_W = 1000;
	const int SCREEN_H = 1000;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *bit = NULL;
	al_init();
	display = al_create_display(500, 400);
	al_init_primitives_addon();
	display = al_create_display(SCREEN_W, SCREEN_H);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	struct MyPoint
	{
		float x, y;

	};

	int num_points = 5;
	MyPoint points[13] =
	{
		{ 0, 500 },//1
		{ 100, 500 },//2
		{ 100, 100 },//3
		{ 200, 600 },//4
		{ 240, 200 },//5
		{ 300, 900 },//6
		{ 400, 500},
		{ 650, 500 },//7
		{ 690, 100 },//8
		{ 790, 600 },//9
		{ 850, 200 },//10
		{ 900, 500 },//11
		{ 1000, 500 },//12

	};
	al_draw_ribbon((float*)points, sizeof(MyPoint), al_map_rgb(150, 0, 0), 2, 13);
	al_flip_display();
	al_rest(20.0);
}

