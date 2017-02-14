#include <stdio.h>
#include <allegro5/allegro.h>
#include <cmath>
#include<allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

const float FPS = 100;
const int SCREEN_W = 1000;
const int SCREEN_H = 1000;

//change this number to change the size of the "marker tip" that draws the shape!
const int BOUNCER_SIZE = 2;

int main(int argc, char **argv) {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_dx = -4.0, bouncer_dy = 4.0;
	bool redraw = true;
	double t = 1;

	al_init();
	al_init_font_addon();//sets up font addon
	ALLEGRO_FONT *font = al_create_builtin_font();
	al_init_primitives_addon();

	timer = al_create_timer(1.0 / FPS);

	display = al_create_display(SCREEN_W, SCREEN_H);


	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);

	al_set_target_bitmap(bouncer);

	al_clear_to_color(al_map_rgb(255, 0, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	//change the numbers to change the background color, 000 is black
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	struct MyPoint
	{
		float x, y;

	};

	int num_points = 5;
	MyPoint points[12] =
	{
		{ 0, 500 },//1
		{ 100, 500 },//2
		{ 100, 100 },//3
		{ 200, 600 },//4
		{ 240, 200 },//5
		{ 300, 500 },//6
		{ 650, 500 },//7
		{ 690, 100 },//8
		{ 790, 600 },//9
		{ 850, 200 },//10
		{ 900, 500 },//11
		{ 1000, 500 },//12
		
	};

	while (1)
	{

		t++;
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (bouncer_x < 0 || bouncer_x > SCREEN_W - BOUNCER_SIZE) {
				bouncer_dx = -bouncer_dx;
			}

			if (bouncer_y < 0 || bouncer_y > SCREEN_H - BOUNCER_SIZE) {
				bouncer_dy = -bouncer_dy;
			}

			//////////////////////////////////////////////////////////////////////////////////////////////
			//here's the parametric equations that determine the shape!!
			bouncer_x = 250 + 10 * (16 * (sin(t)*(sin(t))*(sin(t))));
			bouncer_y = 230 + (10 * (13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t)))*-1;


			/////////////////////////////////////////////////////////////////////////////////////////////////////
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			//a well-placed if statement here might make it blink

			//uncommenting this line makes it moving dots instead of picture
			//also, change the number values to change the background color 
			// al_clear_to_color(al_map_rgb(0,0,0)); 	

			al_set_target_bitmap(bouncer);

			//mess with this last line here to change colors
			al_clear_to_color(al_map_rgb(150, 0, 0));
			al_set_target_bitmap(al_get_backbuffer(display));
			al_draw_bitmap(bouncer, bouncer_x + 200, bouncer_y + 100, 0);
			al_draw_ribbon((float*)points, sizeof(MyPoint), al_map_rgb(150, 0, 0), 2, 12);
			al_draw_text(font, al_map_rgb(255, 255, 255), 450, 300, ALLEGRO_ALIGN_CENTER, "This is my heart when I'm near you!<3");
			
			al_flip_display();
		}
	}

	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}