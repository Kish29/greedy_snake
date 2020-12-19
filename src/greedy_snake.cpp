#include "greedy_snake.h"

inline void sleep_ms(uint64_t time) {
	timeval t_v;
	t_v.tv_sec = time / 1000;
	t_v.tv_usec = time * 1000;
	select(0, nullptr, nullptr, nullptr, &t_v);
}

void *pthread_work(void *v) {

	for (int i = 0; i < 100; i++) {
		printf("%s\n", "*************************************************************************************************************************");	
		sleep_ms(500);
	}

	complete = true;

	return nullptr;

}

std::vector<uint64_t> screen_ctl() {
	int i, screen_num;

	// get the number of connected screed device
	xcb_connection_t *connnection = xcb_connect(nullptr, &screen_num);

	printf("screen_num is %d\n", screen_num);

	// get screen iterator
	const xcb_setup_t *setup = xcb_get_setup(connnection);
	xcb_screen_iterator_t it = xcb_setup_roots_iterator(setup);
	
	for (i = 0; i < screen_num; i++) {
		xcb_screen_next(&it);
	}

	// get the screen 
	xcb_screen_t *screen = it.data;

	std::vector<uint64_t> data;
	data.push_back((uint64_t)screen->root);
	data.push_back((uint64_t)screen->width_in_pixels);
	data.push_back((uint64_t)screen->height_in_pixels);
	data.push_back((uint64_t)screen->white_pixel);
	data.push_back((uint64_t)screen->black_pixel);
	return data;
}

int main(int argc, char **argv, char **envp) {
	
	pthread_t *p = new pthread_t;

	auto scrn = screen_ctl();

	auto p_scrn = scrn.begin();

	while (p_scrn != scrn.end()) {
		printf("%ld\n", *p_scrn);
		p_scrn++;
	}

	pthread_create(p, nullptr, pthread_work, nullptr);

	while (!complete);

	return 0;

}
