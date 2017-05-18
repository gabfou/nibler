// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/05/18 17:28:16 by gfournie          #+#    #+#             //
//   Updated: 2017/05/18 17:28:56 by gfournie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "le.hpp"


void ft_error(std::string str)
{
	std::cout << str << "\n";
	exit(-1);
}

void headrenderer(t_env *env)
{

}

void initglfw(t_env *env)
{
	void *glfw;
	void* window;
	// GLuint vertex_buffer, vertex_shader, fragment_shader, program;
	// GLint mvp_location, vpos_location, vcol_location;


	glfw = dlopen("./glfw/libglfw.3.2.dylib", RTLD_LAZY | RTLD_LOCAL);
	if (!glfw)
		ft_error("dafuq227");

	int (*glfwInit)(void) = (int(*)(void))dlsym(glfw, "glfwInit");
	void(*glfwMakeContextCurrent)(void*) = (void(*)(void*))dlsym(glfw, "glfwMakeContextCurrent");
	void(*glfwTerminate)(void) = (void(*)(void))dlsym(glfw, "glfwTerminate");
	void*(*glfwCreateWindow)(int, int, const char*, void*, void*) = (void*(*)(int, int, const char*, void*, void*))dlsym(glfw, "glfwCreateWindow");
	int(*glfwWindowShouldClose)(void*) = (int(*)(void*))dlsym(glfw, "glfwWindowShouldClose");
	void(*glClear)(unsigned int) = (void(*)(unsigned int))dlsym(glfw, "glClear");
	void(*glfwSwapBuffers)(void *window) = (void(*)(void*))dlsym(glfw, "glfwSwapBuffers");
	void(*glfwPollEvents)(void) = (void(*)(void))dlsym(glfw, "glfwPollEvents");


	if (!glfwInit || !glfwMakeContextCurrent || !glfwTerminate || !glfwCreateWindow || !glfwWindowShouldClose || !glClear || !glfwSwapBuffers || !glfwPollEvents)
		ft_error("dafuq434");
	if (!glfwInit())
		ft_error("dafuq435");

	window = glfwCreateWindow(640, 480, "nibler", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return ;
	}

	glfwMakeContextCurrent(window);
	while (!glfwWindowShouldClose(window))
    {
        glClear(0x00004000);
        headrenderer(env);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}

int main()
{
	t_env env;
	initglfw(&env);
	return 0;
}
