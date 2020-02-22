#! /bin/sh
ifconfig | grep "ether " | sed "s/ether//g" | tr -d " " | tr -d "\t"
