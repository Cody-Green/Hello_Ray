#pragma once
#include "raylib.h"

struct R_WINDOW
{
	int width = 800;
	int height = 600;
	const char* title = "Default Window";
	bool pause = false;
	int framecount = 0;
};

struct Ball
{
	float radius = 20;
	Vector2 position = { 200.0f, 300.0f };
	Vector2 velocity = { 5.0f, 4.0f };
};