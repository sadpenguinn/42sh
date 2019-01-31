augroup project
    autocmd!
    autocmd BufRead,BufNewFile *.h,*.c set filetype=c
augroup END
let &path.="includes,srcs/libft/includes,srcs/libft/vector,"
