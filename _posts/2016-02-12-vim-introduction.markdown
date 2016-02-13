# Text Editor
[VIM](http://www.vim.org)   
emacs   
[Atom](https://atom.io/)   
Sublime Text   

# VIM

[Offical site of vim](http://www.vim.org)

[Plugins](http://vim-scripts.org/)




# How to view code in vim?
	ctags
	cscope
	cflow
	calltree

	zt			Like "z<CR>", but leave the cursor in the same
				column.  {not in Vi}
	zz			Like "z.", but leave the cursor in the same column.
				Careful: If caps-lock is on, this command becomes
				"ZZ": write buffer and exit!  {not in Vi}
	zb			Like "z-", but leave the cursor in the same column.
				{not in Vi}


# Plugins
~/.vimrc

	Plugin 'VundleVim/Vundle.vim'
	Plugin 'tpope/vim-fugitive'
	Plugin 'vimwiki'
	Plugin 'sotte/presenting.vim'
	Plugin 'plantuml-syntax'
	Plugin 'L9'
	Plugin 'Conque-Shell'
	Plugin 'Mark'
	Plugin 'pathogen.vim'
	Plugin 'mileszs/ack.vim'
	Plugin 'c.vim'
	Plugin 'git://git.wincent.com/command-t.git'
	Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}

# vim script 

	:h script

	:let i = 1
	:while i < 5
	:  echo "count is" i
	:  let i += 1
	:endwhile


# tutor 
	:h tutor


# The End


**Thanks!**

