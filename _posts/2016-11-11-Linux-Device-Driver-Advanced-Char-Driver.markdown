---
layout: post
title:  "Linux Device Driver -- Advanced Char Driver"
date:   2016-11-11 
categories: jekyll update
---

`uname -a`
	peter@peter-ThinkPad-T430:~/work/src/linux/linux/drivers/char/scull$ uname -a
	Linux peter-ThinkPad-T430 3.16.0 #2 SMP Sun Aug 7 18:04:04 CST 2016 x86_64 x86_64 x86_64 GNU/Linux


Error,
	peter@peter-ThinkPad-T430:~/work/src/linux/linux/drivers/char/scull$ make
	make -C /lib/modules/3.16.0/build M=/home/peter/work/src/linux/linux/drivers/char/scull LDDINC=/home/peter/work/src/linux/linux/drivers/char/scull/../include modules
	make[1]: Entering directory `/home/peter/work/src/linux/linux'
	  CC [M]  /home/peter/work/src/linux/linux/drivers/char/scull/main.o
	/home/peter/work/src/linux/linux/drivers/char/scull/main.c:17:26: fatal error: linux/config.h: No such file or directory
	 #include <linux/config.h>
				  ^
	compilation terminated.
	make[2]: *** [/home/peter/work/src/linux/linux/drivers/char/scull/main.o] Error 1
	make[1]: *** [_module_/home/peter/work/src/linux/linux/drivers/char/scull] Error 2
	make[1]: Leaving directory `/home/peter/work/src/linux/linux'
	make: *** [modules] Error 2




# Reference
http://blog.chinaunix.net/uid-24467128-id-3125691.html
[scull在Ubuntu11.10上的编译](http://www.cnblogs.com/xiaoya901109/archive/2012/11/21/2780789.html)

