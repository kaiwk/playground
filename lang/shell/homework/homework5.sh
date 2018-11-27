#!/bin/bash


add_group() {
	egrep "$1" /etc/group >& /dev/null
	if [[ $? != 0 ]]; then
		sudo groupadd $1
	fi
}

add_user() {
	id $1 >& /dev/null
	if [[ $? != 0 ]]; then
		sudo useradd $1
	fi
}

add_user_dir() {
	if [[ -d $1 ]]; then
		echo $1 has been already created
	else
		sudo mkdir $1
	fi
}

add_group clas1

for i in {1..30}
do
	if [ $i -le 9 ]; then
		USERNAME=stu0$i
	else
		USERNAME=stu$i
	fi
	add_user $USERNAME
	add_user_dir /home/$USERNAME
	sudo chown -R $USERNAME /home/$USERNAME
	sudo chgrp -R class1 /home/$USERNAME
	i=$((i+1))
done
