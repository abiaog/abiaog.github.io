---
layout: post
title:  "Linux Device Driver -- Advanced Char Driver"
date:   2016-11-11 
categories: jekyll update
---

     

# ioctl

ioctl() is one of the remaining parts of the kernel which runs under the Big Kernel Lock (BKL). In the past, the usage of the BKL has made it possible for long-running ioctl() methods to create long latencies for unrelated processes.

## What is the difference between ioctl(), unlocked_ioctl() and compat_ioctl()?

http://unix.stackexchange.com/questions/4711/what-is-the-difference-between-ioctl-unlocked-ioctl-and-compat-ioctl



# Reference

