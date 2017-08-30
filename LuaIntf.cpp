// LuaIntf.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <boost/timer/timer.hpp>
#include <LuaIntf/LuaIntf.h>

#include <iostream>

using namespace LuaIntf;
using namespace std;

int add(int a, int b)
{
	return a + b;
}

void add_times(int a, int b, int times)
{
	for (int i = 0; i < times; ++i)
		add(a, b);
}

extern "C" int LuaOpenModule_Test(lua_State* L)
{
	assert(L);
	using namespace LuaIntf;
	LuaRef mod = LuaRef::createTable(L);
	LuaBinding(mod)
		.addFunction("add", add)
		.addFunction("add_times", add)
		;
	mod.pushToStack();
	return 1;
}

int main()
{
	LuaContext luaCtx;
	lua_State* L = luaCtx.state();

	LuaRef table(L, "package.preload");
	table["c_test"] = LuaRef::createFunctionWith(L, LuaOpenModule_Test);

	LuaRef require(L, "require");
	LuaRef test = require.call<LuaRef>("test");

	const int COUNT = 10000000;

	cout << "C++ calls lua add() many times:\n";
	{
		boost::timer::auto_cpu_timer t;
		for (int i = 0; i < COUNT; ++i)
			test.dispatchStatic("add", 123, 456);
	}
	cout << "C++ calls lua add_times() once:\n";
	{
		boost::timer::auto_cpu_timer t;
		test.dispatchStatic("add_times", 123, 456, COUNT);
	}
	cout << "Lua calls C++ add() many times:\n";
	{
		boost::timer::auto_cpu_timer t;
		test.dispatchStatic("test_c_add", 123, 456, COUNT);
	}
	cout << "Lua calls C++ add_times() once:\n";
	{
		boost::timer::auto_cpu_timer t;
		test.dispatchStatic("test_c_add_times", 123, 456, COUNT);
	}

	return 0;
}

