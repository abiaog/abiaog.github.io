



# How to download an entire website as plain text documents?

In some cases, I would like to read html documents with VIM if all of the contents are plain text.
First, wget the whole site do local machine. And then, filter all the html files into correct order. Finally,using some plain text browser, for example, elinks to dump the contents into plain text.


## wget the entire web site

	#/bin/bash
	wget \
		--recursive \
		--no-clobber \
		--page-requisites \
		--html-extension \
		--convert-links \
		--restrict-file-names=windows \
		--domains kernel.org \
		--no-parent \
		https://www.kernel.org/doc/gorman/html/understand/


## dump html contents into plain text (or dump html one by one)

elinks -dump https://www.kernel.org/doc/gorman/html/understand/understand008.html > BootMemoryAllocator.txt
elinks -dump https://www.kernel.org/doc/gorman/html/understand/understand008.html >> <more contents>



[Downloading an Entire Web Site with wget](http://www.linuxjournal.com/content/downloading-entire-web-site-wget)


#  How to extract tar.bz2?

	tar -jxvf qemu-2.0.2.tar.bz2



