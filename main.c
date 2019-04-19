#include <stdio.h>
#include <dlfcn.h>
#include "test.h"

int load_dynamic_fun() {
	void* handle = dlopen("libtest.so", RTLD_LAZY);
	int (*test)() = dlsym (handle, "test_my_function");
	int (*test2)() = dlsym (handle, "test_get_value");
	(*test)();
	printf("test get value is %d\n", (*test2)());
	dlclose(handle);
	return 0;
}

int  main() {
	int a = 0;
	int b = 100;

	int c = 0;


	c = a + b;
	c = c + test_get_value();
	printf("hello %d\n", TEST_NUM);
	printf("c =  %d\n", c);


	load_dynamic_fun();
	return 0;
}
