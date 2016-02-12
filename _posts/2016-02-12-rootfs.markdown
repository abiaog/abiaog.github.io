



Call Tree(kernel 2.6.34)
------
asmlinkage void __init start_kernel(void)
	vfs_caches_init(totalram_pages);
	  mnt_init();
	    init_rootfs();
	    init_mount_tree();

Reference
------
- [rootfs](http://blog.csdn.net/kevin_hcy/article/details/17663341)

