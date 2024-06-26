#pragma once

#include "Lila/Math/Math.h"

#include "Lila/Math/Vectors.h"

#include "Platform/Defines.h"
#include "Platform/Graphics.h"

#include <string>

namespace Lila {

	class Window {
	public:
		Window(std::string name);
		Window(std::string name, b8 maximized);
		Window(std::string name, i32 width, i32 height);
		~Window();

		void render();
		void update();

		bool isOpen();
		bool isClosed();

	#ifdef LILA_GLFW_CONTEXT
		GLFWwindow* getContext() { return window_m; }
	#endif
		std::string getName() { return name_m; }
		Vec2 getSize() { return Vec2{ (f32)width_m, (f32)height_m }; }
	
	private:
		void create();

	private:
	#ifdef LILA_GLFW_CONTEXT
		GLFWwindow* window_m;
		GLFWmonitor* monitor_m;
		const GLFWvidmode* videoMode_m;
	#endif
	
		std::string name_m;
		i32 x_m, y_m;
		i32 width_m, height_m;
		i32 refreshRate_m;
		b8 maximized_m;
		b8 fullscreen_m;

		i32 tempWidth_m, tempHeight_m;
	};
}