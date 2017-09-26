nqueens.cgi: qdriver.o qclass.o
	g++ -static -o nqueens.cgi qdriver.o qclass.o
	
qdriver.o: qdriver.cpp qclass.hpp
	g++ -O2 -c qdriver.cpp
	
qclass.o: qclass.cpp qclass.hpp
	g++ -O2 -c qclass.cpp
	
install:
	sudo cp nqueens.cgi /srv/httpd/cgi-bin
	sudo chown apache:apache /srv/httpd/cgi-bin/nqueens.cgi
	
clean:
	rm nqueens.cgi && rm *.o
