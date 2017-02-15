---
layout: post
title:  "Understanding the Linux Kernel"
date:   2017-02-14
categories: jekyll update
---

# Memory Addressing

## Segment Selectors and Segmentation Registers

To make it easy to retrieve segment selectors quickly, the processor provides segmentation registers whose only purpose is to hold Segment Selectors; these registers are called cs, ss, ds, es, fs and gs.

Three specific purposes,

cs

code segment register

ss 

stack segment register

ds 

data segment regitster


### Current Privilege Level(CPL)



