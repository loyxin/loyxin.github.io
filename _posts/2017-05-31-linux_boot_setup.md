---
layout: post
title:  " Linux GRUB 引导Win 10"
categories: grub
tags: boot 备忘
author: loyxin
---


* content
{:toc}

笔记本电脑先前安装了 `deepin` , 后来想试着安装显卡驱动, 失败, 然后原来的集成显卡的驱动不能用了. 开机不了, 但是不影响 `windows 10`, 不过不知道为什么 突然今天不能用了. 开机进入`grub2`的命令行形式, 不知道为什么以前的那个可以选择`windows`的引导项界面去哪里,于是花了一些时间搜索, 找到了类似的情况.

关键是告诉 `grub` `windows`在哪里.

留作复制代码用

参考 [grub2 invalid-efi-file-path](https://askubuntu.com/questions/216215/invalid-efi-file-path)
```
grub> ls
```
可以看到各个磁盘的格式,大小,UUID(UUID 重要, 后面要用到)

```
insmod part_gpt
insmod fat
set root='(hd0,gpt2)'
search --no-floppy --fs-uuid --set=root `UUID`(这里修改成对应的UUID)
chainloader /EFI/Microsoft/Boot/bootmgfw.efi
boot
```

ok, achieved
