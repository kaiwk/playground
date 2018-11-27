#!/bin/bash

SYSTEM_DES=$(uname -a)
SOURCE_LISTS_PATH=/etc/apt
VIMRC_PATH=$HOME/.vim
SSH_PATH=/etc/ssh
CRONTAB_PATH=/var/spool/cron/crontabs
SYSCTL_PATH=/etc/sysctl.conf

# 更新软件源
back_up_mirror() {
	echo "backup your sources.list"
	sudo mv $SOURCE_LISTS_PATH/sources.list $SOURCE_LISTS_PATH/sources.list.$(date +%F-%R:%S)
}

update_mirror() {
	back_up_mirror
	sudo bash -c "echo deb http://mirrors.163.com/ubuntu/ xenial main universe restricted multiverse >> $SOURCE_LISTS_PATH/sources.list"
	sudo bash -c "echo deb-src http://mirrors.163.com/ubuntu/ xenial main universe restricted multiverse >> $SOURCE_LISTS_PATH/sources.list"
	sudo bash -c "echo deb http://mirrors.163.com/ubuntu/ xenial-security universe main multiverse restricted >> $SOURCE_LISTS_PATH/sources.list"
	sudo bash -c "echo deb-src http://mirrors.163.com/ubuntu/ xenial-security universe main multiverse restricted >> $SOURCE_LISTS_PATH/sources.list"
	sudo bash -c "echo deb http://mirrors.163.com/ubuntu/ xenial-updates universe main multiverse restricted >> $SOURCE_LISTS_PATH/sources.list"
	sudo bash -c "echo deb http://mirrors.163.com/ubuntu/ xenial-proposed universe main multiverse restricted >> $SOURCE_LISTS_PATH/sources.list"
	sudo bash -c "echo deb-src http://mirrors.163.com/ubuntu/ xenial-proposed universe main multiverse restricted >> $SOURCE_LISTS_PATH/sources.list"
	sudo bash -c "echo deb http://mirrors.163.com/ubuntu/ xenial-backports universe main multiverse restricted >> $SOURCE_LISTS_PATH/sources.list"
	sudo bash -c "echo deb-src http://mirrors.163.com/ubuntu/ xenial-backports universe main multiverse restricted >> $SOURCE_LISTS_PATH/sources.list"
	sudo bash -c "echo deb-src http://mirrors.163.com/ubuntu/ xenial-updates universe main multiverse restricted >> $SOURCE_LISTS_PATH/sources.list"
}

# 更新软e
pdate_software() {
	sudo apt-get update
}

# 定时同步时间


# 关闭 SELinux (需要重启)
temporary_shutdown_SELinux() {
	sudo sed -i s/SELINUX=[a-zA-Z]*/SELINUX=disabled/g /etc/selinux/config
}

# 增大文件打开数目
increase_file_limit() {
	ulimim -n 65535
	echo "* increase the limit of open file"
}

# 打开vim高亮
open_vim_syntax() {
	sed -i "s/syntax off/syntax on/g" $VIMRC_PATH/vimrc
	echo "* open vim syntax"
}

# 禁用GSSAPI 
ban_gssapi() {
	local content=$(grep "GSSAPIAuthentication yes" $SSH_PATH/ssh_config)
	if [[ $content != "" ]]; then
		sudo sed -i "s/GSSAPIAuthentication yes/GSSAPIAuthentication no/g" $SSH_PATH/ssh_config
		echo "* bae GSSAPI"
	fi
}

# 禁用 ssh DNS域名反向解析
ban_ssh_dns() {
	local content=$(grep "UseDNS" $SSH_PATH/ssh_config)
	if [[ $content != "" ]]; then
		if [[ $content == "UserDNS yes" ]]; then
			sudo sed -i "s/UseDNS yes/UseDNS no/g" $SSH_PATH/ssh_config
			echo "* ban SSH DNS"
		else
			echo "* Do nothing, because SSH has already banned"
		fi
	else
		sudo bash -c "echo UseDNS no >> $SSH_PATH/ssh_config"
		echo "* ban SSH DNS"
	fi
}

# 同步时间，国家授时中心（借助 ntpdate）
sync_time() {
	local content=$(grep "ntpdate" $CRONTAB_PATH/kermit)
	if [[ $content == "" ]]; then
		echo \# times sync by kermit at $(date +%F) >> $CRONTAB_PATH/kermit
		echo \* 10 \* \* \* ntpdate 210.72.145.44 >> $CRONTAB_PATH/kermit
	fi
	echo \* sync timne success
	echo --- crontab list begin ----
	crontab -l
	echo --- crontab list end ----
	echo
}


# 优化系统控制
improve_system() {
	local content=$(grep "^net.ipv4.tcp" $SYSCTL_PATH)
	if [[ $content == "" ]]; then
		sudo bash -c "echo kernel.core_pattern=/data/logs/core_files/core-%e-%p-%t >> $SYSCTL_PATH"
		sudo bash -c "echo net.core.wmem_default=8388608 >> $SYSCTL_PATH"
		sudo bash -c "echo net.core.rmem_default=8388608 >> $SYSCTL_PATH"
		sudo bash -c "echo net.core.wmem_max=16777216 >> $SYSCTL_PATH"
		sudo bash -c "echo net.core.rmem_max=16777216 >> $SYSCTL_PATH"
		sudo bash -c "echo net.unix.max_dgram_qlen = 100 >> $SYSCTL_PATH"
		sudo bash -c "echo net.ipv4.tcp_syncookies=1 >> $SYSCTL_PATH"
		sudo bash -c "echo net.ipv4.tcp_max_syn_backlog = 81920 >> $SYSCTL_PATH"
		sudo bash -c "echo net.ipv4.tcp_synack_retries = 3 >> $SYSCTL_PATH"
		sudo bash -c "echo net.ipv4.tcp_syn_retries = 3 >> $SYSCTL_PATH"
		sudo bash -c "echo net.ipv4.tcp_fin_timeout = 3 >> $SYSCTL_PATH"
		sudo bash -c "echo net.ipv4.tcp_keepalive_time = 300 >> $SYSCTL_PATH"
		sudo bash -c "echo net.ipv4.tcp_tw_reuse = 1 >> $SYSCTL_PATH"
		sudo bash -c "echo net.ipv4.tcp_tw_recycle = 1 >> $SYSCTL_PATH"
		sudo bash -c "echo net.ipv4.ip_local_port_range = 20000 65000 >> $SYSCTL_PATH"
		sudo bash -c "echo net.ipv4.tcp_max_tw_buckets = 200000 >> $SYSCTL_PATH"
		sudo bash -c "echo net.ipv4.route.max_size = 5242880 >> $SYSCTL_PATH"
		echo "* System improve complete"
	else
		echo "* Do nothing, because system has already improved"
	fi
	
}

# 关闭ipv6
shutdown_ipvsix(){
	local content=$(grep "^net.ipv6.conf" $SYSCTL_PATH)
	if [[ $content == "" ]]; then
		sudo bash -c "echo \# shut down ipv6 >> $SYSCTL_PATH"
		sudo bash -c "echo net.ipv6.conf.all.disable_ipv6 = 1 >> $SYSCTL_PATH"
		sudo bash -c "echo net.ipv6.conf.lo.disable_ipv6 = 1 >> $SYSCTL_PATH"
		echo "* ipv6 shutdown"
	else
		echo "* Do nothing, because ipv6 has been already shuted down"
	fi
}

if [[ $SYSTEM_DES =~ "Linux" && $SYSTEM_DES =~ "x86_64" ]]; then
	open_vim_syntax
#	increase_file_limit
	temporary_shutdown_SELinux
#	update_mirror
#	update_software
	ban_gssapi
	ban_ssh_dns
	sync_time
	improve_system
	shutdown_ipvsix
fi
