#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

using namespace std;

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;
static SDL_Rect camera;
static int number;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 700;
const int SCREEN_BPP = 16;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR = 0Xff;

const int FRAME_PER_SECOND = 30;

#define TILE_SIZE 50
#define MAX_MAP_X 24
#define MAX_MAP_Y 112
#define MAX_TILES 11

typedef struct
{
	int LEFT_;
	int RIGHT_;
	int UP_;
	int v_;
	int x_;
} Input;

typedef struct
{
	int tile[MAX_MAP_Y][MAX_MAP_X];
	string file_name_;
} Map;

#endif