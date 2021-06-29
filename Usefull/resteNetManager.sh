#!/bin/bash

ROUTER_IP=192.168.9.6
( ! ping -c1 $ROUTER_IP >/dev/null 2>&1 ) && /usr/sbin/service network-manager restart