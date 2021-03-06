#include <allegro5/allegro.h>



int main()
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *square = NULL;
	ALLEGRO_BITMAP *square2 = NULL;
	ALLEGRO_BITMAP *ball = NULL;

	//these two variables hold the x and y positions of the square
	//initalize these variables to where you want your square to start
	float square_x = 610;//down
	float square_y = 50;//up
	float square2_x = 10;//w
	float square2_y = 50;//s

	float ball_x = 30;
	float ball_y = 30;
	float ball_dx = -4.0, ball_dy = 4.0;
	//here's our key states. they're all starting as "false" because nothing has been pressed yet.
	//the first slot represents "up", then "down", "left" and "right"
	bool key[2] = { false, false };
	bool key2[2] = { false, false };
	//don't redraw until an event happens
	bool redraw = true;

	//this controls our game loop
	bool doexit = false;

	al_init();


	//get the keyboard ready to use
	al_install_keyboard();

	timer = al_create_timer(.02);

	display = al_create_display(640, 480);

	ball = al_create_bitmap(32, 32);

	al_set_target_bitmap(ball);
	al_clear_to_color(al_map_rgb(255, 100, 100));
	square = al_create_bitmap(20, 120);


	al_set_target_bitmap(square);

	al_clear_to_color(al_map_rgb(255, 255, 255));
	square2 = al_create_bitmap(20, 120);


	al_set_target_bitmap(square2);

	al_clear_to_color(al_map_rgb(255, 255, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	//these lines tell teh event source what to look for
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	//new! tell the event queue that it should take keyboard events, too 
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	//so the game loop is set to act on "ticks" of the timer OR keyboard presses 
	//OR the mouse closing the display
	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {
		
			//if the box hits the left wall OR the right wall
			if (ball_x < 0 || ball_x > 640 - 32) {
				//flip the x direction
				ball_dx = -ball_dx;
			}
			//if the box hits the top wall OR the bottom wall
			if (ball_y < 0 || ball_y > 480 - 32) {
				//flip the y direction
				ball_dy = -ball_dy;
			}

			//really important code!
			//move the box in a diagonal
			ball_x += ball_dx;
			ball_y += ball_dy;

			//if an event happened, you better redraw
			redraw = true;
		
		//////////////////////////////////players movement/////////////////////////////////////////////////////////////
		//here's the movement algorithm

		
			//if the up button is pressed AND we're still below the top wall,
			//move the box "up" by 4 pixels
			if (key[0] && square_y >= 0) {
				square_y -= 4.0;
			}
			if (key2[0] && square2_y >= 0) {
				square2_y -= 4.0;
			}

			//if the down button is pressed AND we're still above the bottom wall
			//move the box "down" by 4 pixels
			if (key[1] && square_y <= 480 - 32) {
				square_y += 4.0;
			}
			if (key2[1] && square2_y <= 480 - 32) {
				square2_y += 4.0;
			}


			//redraw at every tick of the timer
			redraw = true;
		}

		///////////////////////////////////////////////////////////////////////////////////////////////////////
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////
		//here's the algorithm that turns key presses into events
		//a "key down" event is when a key is pushed
		//while a "key up" event is when a key is released

		//has something been pressed on the keyboard?
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {

			//"keycode" holds all the different keys on the keyboard
			switch (ev.keyboard.keycode) {

				//if the up key has been pressed
			case ALLEGRO_KEY_UP:
				key[0] = true;
				break;

			case ALLEGRO_KEY_W:
				key2[0] = true;
				break;

				//if the down key has been pressed
			case ALLEGRO_KEY_DOWN:
				key[1] = true;
				break;

			case ALLEGRO_KEY_S:
				key2[1] = true;
				break;

			}
		}
		//has something been released on the keyboard?
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[0] = false;
				break;

			case ALLEGRO_KEY_W://up
				key2[0] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[1] = false;
				break;

			case ALLEGRO_KEY_S://down
				key2[1] = false;
				break;

				//kill the program if someone presses escape
			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;

			}
		}


		//RENDER SECTION
		//if the clock ticked but no other events happened, don't bother redrawing
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			//paint black over the old screen, so the old square dissapears
			al_clear_to_color(al_map_rgb(0, 0, 0));

			//the algorithm above just changes the x and y coordinates
			//here's where the bitmap is actually drawn somewhere else
			al_draw_bitmap(square, square_x, square_y, 0);
			al_draw_bitmap(square2, square2_x, square2_y, 0);
			//here's where the magic happens: draw the square to the screen
			//at the coordinate position bouncer_x, bouncer_y
			al_draw_bitmap(ball, ball_x, ball_y, 0);
			al_flip_display();
		}
	}
	al_destroy_bitmap(ball);
	al_destroy_bitmap(square);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}