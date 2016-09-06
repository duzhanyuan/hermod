/*
 * Hermod - Modular application framework
 *
 * Copyright (c) 2016 Cowlab
 *
 * Hermod is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License 
 * version 3 as published by the Free Software Foundation. You
 * should have received a copy of the GNU Lesser General Public
 * License along with this program, see LICENSE file for more details.
 * This program is distributed WITHOUT ANY WARRANTY see README file.
 *
 * Authors: Saint-Genest Gwenael <gwen@hooligan0.net>
 */
#include "ModuleCache.hpp"
#include "Router.hpp"
#include "Session.hpp"

using namespace  hermod;

class App
{
public:
	static void destroy();
	App * exec (void);
	App * init (void);
	static App* getInstance();
public:
	static void sigInt(void);
protected:
	void processFcgi (void);
private:
	App();
	~App();
private:
    	static App*  mAppInstance;
	bool         mRunning;
	int          mFcgxSock;
	Router      *mRouter;
	Session     *mSession;
	ModuleCache  mModuleCache;
};
