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


### Linux Kernel Development(3rd edition)

#### struct page

"struct page" stands for physical page.

	struct page {
		unsigned long flags; // pageflags in  ./include/linux/page-flags.h
		atomic_t _count; // usage count, check with page_count()
		atomic_t _mapcount;
		unsigned long private;
		struct address_space *mapping;
		pgoff_t index;
		struct list_head lru;
		void *virtual; // page virtual address

	};

FILE: ./include/linux/mm_types.h (version: Linux 4.0-rc1)

	struct page {
		/* First double word block */
		unsigned long flags;		/* Atomic flags, some possibly
						 * updated asynchronously */
		union {
			struct address_space *mapping;	/* If low bit clear, points to
							 * inode address_space, or NULL.
							 * If page mapped as anonymous
							 * memory, low bit is set, and
							 * it points to anon_vma object:
							 * see PAGE_MAPPING_ANON below.
							 */
			void *s_mem;			/* slab first object */
		};

		/* Second double word */
		struct {
			union {
				pgoff_t index;		/* Our offset within mapping. */
				void *freelist;		/* sl[aou]b first free object */
				bool pfmemalloc;	/* If set by the page allocator,
							 * ALLOC_NO_WATERMARKS was set
							 * and the low watermark was not
							 * met implying that the system
							 * is under some pressure. The
							 * caller should try ensure
							 * this page is only used to
							 * free other pages.
							 */
			};

			union {
	#if defined(CONFIG_HAVE_CMPXCHG_DOUBLE) && \
		defined(CONFIG_HAVE_ALIGNED_STRUCT_PAGE)
				/* Used for cmpxchg_double in slub */
				unsigned long counters;
	#else
				/*
				 * Keep _count separate from slub cmpxchg_double data.
				 * As the rest of the double word is protected by
				 * slab_lock but _count is not.
				 */
				unsigned counters;
	#endif

				struct {

					union {
						/*
						 * Count of ptes mapped in
						 * mms, to show when page is
						 * mapped & limit reverse map
						 * searches.
						 *
						 * Used also for tail pages
						 * refcounting instead of
						 * _count. Tail pages cannot
						 * be mapped and keeping the
						 * tail page _count zero at
						 * all times guarantees
						 * get_page_unless_zero() will
						 * never succeed on tail
						 * pages.
						 */
						atomic_t _mapcount;

						struct { /* SLUB */
							unsigned inuse:16;
							unsigned objects:15;
							unsigned frozen:1;
						};
						int units;	/* SLOB */
					};
					atomic_t _count;		/* Usage count, see below. */
				};
				unsigned int active;	/* SLAB */
			};
		};

		/* Third double word block */
		union {
			struct list_head lru;	/* Pageout list, eg. active_list
						 * protected by zone->lru_lock !
						 * Can be used as a generic list
						 * by the page owner.
						 */
			struct {		/* slub per cpu partial pages */
				struct page *next;	/* Next partial slab */
	#ifdef CONFIG_64BIT
				int pages;	/* Nr of partial slabs left */
				int pobjects;	/* Approximate # of objects */
	#else
				short int pages;
				short int pobjects;
	#endif
			};

			struct slab *slab_page; /* slab fields */
			struct rcu_head rcu_head;	/* Used by SLAB
							 * when destroying via RCU
							 */
			/* First tail page of compound page */
			struct {
				compound_page_dtor *compound_dtor;
				unsigned long compound_order;
			};

	#if defined(CONFIG_TRANSPARENT_HUGEPAGE) && USE_SPLIT_PMD_PTLOCKS
			pgtable_t pmd_huge_pte; /* protected by page->ptl */
	#endif
		};

		/* Remainder is not double word aligned */
		union {
			unsigned long private;		/* Mapping-private opaque data:
							 * usually used for buffer_heads
							 * if PagePrivate set; used for
							 * swp_entry_t if PageSwapCache;
							 * indicates order in the buddy
							 * system if PG_buddy is set.
							 */
	#if USE_SPLIT_PTE_PTLOCKS
	#if ALLOC_SPLIT_PTLOCKS
			spinlock_t *ptl;
	#else
			spinlock_t ptl;
	#endif
	#endif
			struct kmem_cache *slab_cache;	/* SL[AU]B: Pointer to slab */
			struct page *first_page;	/* Compound tail pages */
		};

	#ifdef CONFIG_MEMCG
		struct mem_cgroup *mem_cgroup;
	#endif

		/*
		 * On machines where all RAM is mapped into kernel address space,
		 * we can simply calculate the virtual address. On machines with
		 * highmem some memory is mapped into kernel virtual memory
		 * dynamically, so we need a place to store that address.
		 * Note that this field could be 16 bits on x86 ... ;)
		 *
		 * Architectures with slow multiplication can define
		 * WANT_PAGE_VIRTUAL in asm/page.h
		 */
	#if defined(WANT_PAGE_VIRTUAL)
		void *virtual;			/* Kernel virtual address (NULL if
						   not kmapped, ie. highmem) */
	#endif /* WANT_PAGE_VIRTUAL */

	#ifdef CONFIG_KMEMCHECK
		/*
		 * kmemcheck wants to track the status of each byte in a page; this
		 * is a pointer to such a status block. NULL if not tracked.
		 */
		void *shadow;
	#endif

	#ifdef LAST_CPUPID_NOT_IN_PAGE_FLAGS
		int _last_cpupid;
	#endif
	}
	/*
	 * The struct page can be forced to be double word aligned so that atomic ops
	 * on double words work. The SLUB allocator can make use of such a feature.
	 */
	#ifdef CONFIG_HAVE_ALIGNED_STRUCT_PAGE
		__aligned(2 * sizeof(unsigned long))
	#endif
	;


#### struct zone

"zone" is logical concept used to organize the pages according to their attributes.

FILE: ./include/linux/mmzone.h

	enum zone_type {
		ZONE_DMA,
		ZONE_DMA32,
		ZONE_NORMAL,
		ZONE_HIGHMEM,
		ZONE_MOVABLE,
		__MAX_NR_ZONES
	};


	struct zone {
		/* Read-mostly fields */

		/* zone watermarks, access with *_wmark_pages(zone) macros */
		unsigned long watermark[NR_WMARK];

		const char		*name;  // "DMA", "Normal", "HighMem"

		/* Write-intensive fields used from the page allocator */
		spinlock_t		lock;
	} ____cacheline_internodealigned_in_smp;


#### allocate pages

FILE: ./include/linux/gfp.h

	struct page *alloc_pages(gfp_t gfp_mask, unsigned int order)
	  |
	  |-> struct page *alloc_pages_current(gfp_t gfp, unsigned order) /*	@gfp:
									   *		%GFP_USER   user allocation,
									   *      	%GFP_KERNEL kernel allocation,
									   *      	%GFP_HIGHMEM highmem allocation,
									   *      	%GFP_FS     don't call back into a file system.
									   *      	%GFP_ATOMIC don't sleep.
									   */	@order: Power of two of allocation size in pages. 0 is a single page.
 
"page_address" is used to convert physical page into logical address,

	void *page_address(const struct page *page);





### Reference

[Why is page size 4 kb in most operating systems?](https://www.quora.com/Why-is-page-size-4-kb-in-most-operating-systems)

[Why is page size 4KB](http://stackoverflow.com/questions/11783981/is-number-of-frame-number-of-pageslinux])

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

