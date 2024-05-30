#pragma once

#include "Lila/Core/Logger.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

static bool initDependencies() {
#ifndef HEADLESS
	if(!glfwInit()) {
		lila_fatal("Failed to initialize GLFW!")
		return false;
	}

	lila_trace("Initialized GLFW");
	lila_info("GLFW version %d.%d.%d", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);
  #endif
	return true;
}

static bool initOpenGL() {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		lila_fatal("Failed to initialize OpenGL!")
			return false;
	}

	lila_trace("Initialized OpenGL");
	lila_info("OpenGL version %s", glGetString(GL_VERSION));

	return true;
}
}
