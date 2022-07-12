#!/bin/bash
wall "  #Architecture: $(uname -a)
        #CPU physical: $(nproc)
        #vCPU: $(cat /proc/cpuinfo | grep processor | wc -l)
        #Memory Usage: $(free --mega | awk 'NR==2 {printf "%s/%sMB (%.2f%%)", $3, $2, $3*100/$2}')
        #Disk Usage: $(df -h | awk 'NR==4 {printf "%d/%.1fGB (%s)", $3*1000, $2, $5}')
        #CPU load: $(top -bn1 | awk 'NR==3 {printf "%.2f%%", $4 + $2}')
        #Last boot: $(who -b | awk '{printf "%s %s", $3, $4}')
        #LVM use: $(/usr/sbin/lvm pvdisplay | grep Allocatable | awk '{printf "%s", $2}')
        #Connexions TCP: $(ss -s | grep TCP | awk 'NR==2 {printf "%d ESTABLISHED", $3}')
        #User log: $(users | wc -w)
        #Network: IP $(hostname -I)$(ip a | grep link/ether | awk '{printf "(%s)", $2}')
        #Sudo: $(cat /var/log/sudo/sudolog | grep COMMAND | wc -l | awk '{printf "%d cmd", $0}')"
