#include "CommonFunction.h"
#include "BaseObject.h"
#include "GameMap.h"
#include "MainObject.h"
#include "ImgTimer.h"

BaseObject g_background[8];
BaseObject Menu;
BaseObject Victory;
BaseObject Tutorial;

Mix_Music* music1;
Mix_Music* music2;
Mix_Music* music3;


bool InitData()
{
	bool success = true;
	int ret = SDL_Init(SDL_INIT_VIDEO);
	if (ret < 0) return false;
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	g_window = SDL_CreateWindow("Game Jump King", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (g_window == NULL)
	{
		success = false;
	}
	else
	{
		g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
		if (g_screen == NULL)
		{
			success = false;
		}
		else
		{
			SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) && imgFlags))
			{
				success = false;
			}
		}
	}
	return success;
}

void LoadBackground()
{
	Menu.LoadImg("Map/Menu.png", g_screen);
	Victory.LoadImg("Map/Victory.png", g_screen);
	Tutorial.LoadImg("Map/Tutorial.png", g_screen);

	char file_img[10];
	for (int i = 0; i < 8; i++)
	{
		sprintf_s(file_img, "Img/%d.png", i);
		g_background[i].LoadImg(file_img, g_screen);
	}
}

bool Win(float x, float y)
{
	if (y == 300 && x < 700 && x > 649)
	{
		return true;
	}
	return false;
}

void close()
{
	for (int i = 0; i < 8; i++)
	{
		g_background[i].Free();
	}

	Menu.Free();
	Victory.Free();
	Tutorial.Free();

	SDL_DestroyRenderer(g_screen);
	g_screen;
	SDL_DestroyWindow(g_window);
	g_window = NULL;
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* argv[])
{
	ImgTimer fps_timer;

	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	music1 = Mix_LoadMUS("Sound/Fluffing a Duck - Vanoss Gaming Background Music.wav");
	music2 = Mix_LoadMUS("Sound/Arena of Valor background music season 21.wav");
	music3 = Mix_LoadMUS("Sound/Tokyo 1964 Olympic Games - Olympic March.wav");

	if (InitData() == false)
	{
		return -1;
	}

	LoadBackground();

	bool off = 1;

	bool menu = 1;
	bool tutorial = 1;
	while (menu)
	{
		if (!off)
		{
			Mix_HaltMusic();
		}


		if (!Mix_PlayingMusic() && off)
		{
			Mix_PlayMusic(music2, 0);
		}

		SDL_RenderClear(g_screen);
		if (tutorial)
		{
			Menu.Render(g_screen, NULL);
		}
		else
		{
			Tutorial.Render(g_screen, NULL);
		}
		SDL_RenderPresent(g_screen);
		while (SDL_PollEvent(&g_event) != false)
		{
			if (g_event.type == SDL_QUIT)
			{
				close();
				return 0;
			}
			if (g_event.type == SDL_KEYDOWN)
			{
				switch (g_event.key.keysym.sym)
				{
				case SDLK_y:
				{
					Mix_HaltMusic();
					menu = 0;
				}
				break;
				case SDLK_n:
				{
					close();
					return 0;
				}
				case SDLK_t:
				{
					if (tutorial)
					{
						tutorial = 0;
					}
				}
				break;
				case SDLK_o:
				{
					if (off)
					{
						off = 0;
					}
					else
					{
						off = 1;
					}
				}
				break;
				}
			}
		}
	}

	bool reset = true;
	while (reset)
	{
		number = 1;
		camera.x = 0;

		GameMap game_map;
		game_map.LoadMap("Map/TileMap.txt");
		game_map.LoadTiles(g_screen);

		MainObject player;
		player.LoadImg("Img/v.png", g_screen);
		player.set_clips();
		player.LoadMix();

		bool in_quit = false;
		while (!in_quit)
		{
			fps_timer.start();
			while (SDL_PollEvent(&g_event) != false)
			{
				if (g_event.type == SDL_QUIT)
				{
					in_quit = true;
					reset = false;
				}
				if (g_event.type == SDL_KEYDOWN)
				{
					switch (g_event.key.keysym.sym)
					{
					case SDLK_n:
					{
						close();
						return 0;
					}
					break;
					case SDLK_o:
					{
						if (off)
						{
							off = 0;
						}
						else
						{
							off = 1;
						}
					}
					break;
					}
				}
				player.HandelInputAction(g_event, g_screen);
			}

			player.off(off);

			SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
			SDL_RenderClear(g_screen);
			Map map_data_ = game_map.getMap();
			player.DoPlayer(map_data_);
			number = (player.y_pos_get() + (TILE_SIZE / 2)) / SCREEN_HEIGHT;
			camera.y = number * 700;
			g_background[number].Render(g_screen, NULL);
			game_map.DrawMap(g_screen, number);
			player.Show(g_screen, camera.y);
			SDL_RenderPresent(g_screen);

			int real_imp_timer = fps_timer.get_tick_();
			int timer_one_frame = 1000 / FRAME_PER_SECOND;
			if (real_imp_timer < timer_one_frame)
			{
				int delay_timer = timer_one_frame - real_imp_timer;
				SDL_Delay(delay_timer);
			}

			if (!off)
			{
				Mix_HaltMusic();
			}

			if (!Mix_PlayingMusic() && off)
			{
				Mix_PlayMusic(music1, 0);
			}

			ofstream file("Map/Pos_.txt");
			file << player.x_pos_get() << endl;
			file << player.y_pos_get();
			file.close();

			if (Win(player.x_pos_get(), player.y_pos_get()))
			{
				Mix_PlayMusic(music3, 0);

				float x_pos, y_pos;
				ifstream infile("Map/pos.txt");
				infile >> x_pos;
				infile >> y_pos;
				infile.close();
				ofstream outfile("Map/Pos_.txt");
				outfile << x_pos << endl;
				outfile << y_pos;
				outfile.close();

				bool play = 1;
				while (play)
				{
					if (!off)
					{
						Mix_HaltMusic();
					}

					if (!Mix_PlayingMusic() && off)
					{
						Mix_PlayMusic(music3, 0);
					}

					SDL_RenderClear(g_screen);
					Victory.Render(g_screen, NULL);
					SDL_RenderPresent(g_screen);

					while (SDL_PollEvent(&g_event) != false)
					{
						if (g_event.type == SDL_QUIT)
						{
							close();
							return 0;
						}
						if (g_event.type == SDL_KEYDOWN)
						{
							switch (g_event.key.keysym.sym)
							{
							case SDLK_y:
							{
								Mix_HaltMusic();
								play = 0;
								in_quit = true;
							}
							break;
							case SDLK_x:
							{
								close();
								return 0;
							}
							break;
							case SDLK_o:
							{
								if (off)
								{
									off = 0;
								}
								else
								{
									off = 1;
								}
							}
							break;
							}
						}
					}
				}
			}
		}
	}
	close();
	return 0;
}