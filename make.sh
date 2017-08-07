#!/bin/sh
set -v
#g++ -O2 -c qclass.cpp
g++ -O2 -c qdriver.cpp
g++ -s -o nqueens.cgi qdriver.o qclass.o
sudo cp nqueens.cgi /home/http/cgi-bin/nqueens.cgi
sudo chown apache:apache /home/http/cgi-bin/nqueens.cgi
