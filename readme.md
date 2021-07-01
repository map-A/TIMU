this project is for ourselves.

We only do leetcode problem by yourself.

You Need $\color{red}{NOT}$ write any comments for others.

If you have some problem, you can ask for whom you want to ask!

Sincerely! My honey!

git 上传有时候不成功，使用\
为git设置代理\
`git config --global http.proxy http://127.0.0.1:1080`\
`git config --global https.proxy http://127.0.0.1:1080`

git 取消代理\
`git config --global --unset http.proxy`\
`git config --global --unset https.proxy`

统计写了多少行代码？在git project下执行

`git log  --pretty=tformat: --numstat | awk '{ add += $1; subs += $2; loc += $1 - $2 } END { printf "added lines: %s, removed lines: %s, total lines: %s\n", add, subs, loc }'`
