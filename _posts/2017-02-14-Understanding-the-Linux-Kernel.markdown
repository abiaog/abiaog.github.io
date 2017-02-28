---
layout: post
title:  "Understanding the Linux Kernel"
date:   2017-02-14 
categories: jekyll update
---


# Chapter 1. Memory Addressing

## Memory Addresses

* Logical address
	Each logical address consists of a `segment` and an `offset` that denotes the distance from the start of the segment to the actual address.
* Linear address(also known as virtual address)
	
* Physical address

	Logical address -> |segmentation unit| -> Linear address -> | paging unit| -> Physical address
		Figure 2-1. Logical address translation

## Segment Selectors and Segmentation Registers

To make it easy to retrieve segment selectors quickly, the processor provides segmentation registers whose only purpose is to hold Segment Selectors; these registers are called cs, ss, ds, es, fs and gs.

Three specific purposes,

cs

code segment register

ss 

stack segment register

ds 

data segment regitster

### Segment Descriptors

Segment Descriptors are stored either in the Global Descriptor Table(GDT) or the the Local Descriptor Table(LDT).


### Current Privilege Level(CPL)


### The Linux GDT
In uniprocessor systems there is only one GDT, while in multiprocessor systems there is one GDT for every CPU in the system.

Task State Segment(TSS), different for each processor in the system.

[page frames](http://stackoverflow.com/questions/11783981/is-number-of-frame-number-of-pageslinux])

[Why is page size 4 kb in most operating systems?](https://www.quora.com/Why-is-page-size-4-kb-in-most-operating-systems)

[how is page size determined in virtual address space?](http://unix.stackexchange.com/questions/128213/how-is-page-size-determined-in-virtual-address-space)

[Why using hierarchical page tables?](http://stackoverflow.com/questions/9834542/why-using-hierarchical-page-tables)

[控制寄存器(CR0,CR1,CR2,CR3)和CR4](http://blog.chinaunix.net/uid-29512885-id-4575143.html)



# Chapter 20. Program ExZecution

## Program Segments and Process Memory Regions

* Text Segment
* Initiallized data segment
* Uninitialized data segment (bss)
* Stack segment


# Reference

