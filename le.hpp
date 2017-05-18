// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   le.hpp                                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/05/18 17:28:16 by gfournie          #+#    #+#             //
//   Updated: 2017/05/18 17:28:56 by gfournie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <dlfcn.h>
#include <iostream>
#include "glfw3.h"
// #include "glfw3native.h"

typedef struct	s_env
{
	void *window;
}				t_env;