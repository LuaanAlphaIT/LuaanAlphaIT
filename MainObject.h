#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "BaseObject.h"
#include "CommonFunction.h"

static int num_jump_left_ = 0;
static int num_jump_right_ = 0;
static int num_left_ = 0;
static int num_right_ = 0;
static int num_up_ = 0;
static int max_up = 40;

#define GRAVITY_SPEED 3
#define GO_SPEED 3
#define MAX_FALL_SPEED 25
#define PLAYER_SPEED  5
#define JUMP_SPEED 3
#define MAX_Y_UP 45
#define MAX_X_GO 45

class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();
	bool LoadImg(string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des, int camy);
	void HandelInputAction(SDL_Event events, SDL_Renderer* screen);
	void set_clips();
	void DoPlayer(Map& map_data);
	void CheckToMap(Map& map_data);
	float y_pos_get() { return y_pos_; }
	float x_pos_get() { return x_pos_; }
	void LoadMix();
	void off(bool Off) { off_ = Off; }
private:
	float x_val_;
	float y_val_;
	float x_pos_;
	float y_pos_;
	SDL_Rect frame_clip_[5];
	Input input_type_;
	int frame_;
	bool on_ground;
	Mix_Chunk* sound_effect[3];
	bool off_;
};

#endif