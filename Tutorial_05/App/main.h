#ifndef _MAIN_H
#define _MAIN_H

#define APP_NAME			"Tutorial_00"
#define APP_AUTHOR			"deadevilx"
#define GIT_REPO			"git@github.com/" APP_AUTHOR "/Tutorials.git"

struct Circle {
	double center_x;
	double center_y;
	double radius;
};

typedef struct {
	Circle base;
	double height;
} Cone;

#endif
