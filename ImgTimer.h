#ifndef  IMG_TIMER_H_
#define  IMG_TIMER_H_


class ImgTimer
{
public:
	ImgTimer();
	~ImgTimer();
	void start();
	int get_tick_();
private:
	int start_tick_;
	int paused_tick_;
	bool is_started_;
	bool is_paused_;
};

#endif