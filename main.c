#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <pthread.h>
#include "test.h"


pthread_t my_thread;
int my_data = 5;

void * thread_func(void *pdata) {
	int *ptmp;
	int counter = 0;

	ptmp = (int*)pdata;
	counter = *ptmp;
	printf("enter my thread, pid: %d\n", (int) getpid());
	printf("enter my thread, print number: %d\n", counter);
	while(counter-- >= 0) {
		sleep(1);
		printf("thread_func, counter:%d\n", counter);
	}
	return NULL;
}

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
	printf("main, pid: %d\n", (int) getpid());
	printf("hello %d\n", TEST_NUM);
	printf("c =  %d\n", c);


	load_dynamic_fun();



	pthread_create(&my_thread, NULL, thread_func, &my_data);
	//while(1) {
	//	sleep(5);
	//}
	pthread_join(my_thread, NULL);
	return 0;
}
