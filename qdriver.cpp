#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "qclass.hpp"

void readQueryString(char []);

int main()
{
   // variable declarations
   int n = 0;
   char card[80];
   std::string buf;

   std::cout << "Content-Type:text/html;charset=UTF-8\n\n";
   readQueryString(card);
   // perform preliminary html emission chores
   std::cout << "<!DOCTYPE HTML>" << std::endl;
   std::cout << "<head>" << std::endl;
   std::cout << "<meta charset=\"utf-8\">" << std::endl;
   std::cout << "<title>Sputnik</title>" << std::endl;
   std::cout << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">" << std::endl;
   // initial pass - print the form
   if (strcmp(card, "step1") == 0) {
      std::cout << "</head>" << std::endl;
      std::cout << "<body>" << std::endl;
      std::cout << "<form action=\"nqueens.cgi?step2\" method=\"post\">";
      std::cout << "<div>enter dimenions of n x n chess board (4 - 10)</div>" << std::endl;
      std::cout << "<input type=\"text\" name=\"N\" size=\"2\" value=\"\">" << std::endl;
      std::cout << "<input type=\"submit\" value=\"SUBMIT\"></form>" << std::endl;
   }
   else {
      std::getline(std::cin, buf);
      std::stringstream ss;
      ss << buf;
      ss.ignore(80, '=');
      if (ss.good())
         ss >> n;
      else
         return 1;
      if (n < 4 || n > 10) {
         std::cout << "</head>" << std::endl;
         std::cout << "<body>" << std::endl;
         std::cout << "<p>I'm sorry Dave, I'm afraid I can't do that.</p>" << std::endl;
         std::cout << "</body>" << std::endl;
         std::cout << "</html>" << std::endl;
         return 1;
      }
      queens_on_board composer(n);    // constructor
      // html & css chores - put out the board
      int board_dim = n * 60;
      // chessboard
      std::cout << "<style type=\"text/css\">" << std::endl;
      std::cout << ".chessboard {" << std::endl;
      std::cout << "width: " << board_dim << "px;" << std::endl;
      std::cout << "height: " << board_dim << "px;" << std::endl;
      // std::cout << "max-width: 100%;" << std::endl;
      std::cout << "margin: 20px;" << std::endl;
      // std::cout << "border: 25px solid #333;" << std::endl;
      std::cout << "display: table;" << std::endl;
      std::cout << "table-layout: fixed;" << std::endl;
      std::cout << "}" << std::endl;
      // black square
      std::cout << ".black {" << std::endl;
      std::cout << "width: 60px;" << std::endl;
      std::cout << "height: 60px;" << std::endl;
      std::cout << "background-color: #228b22;" << std::endl;
      std::cout << "font-size:50px;" << std::endl;
      std::cout << "text-align:center;" << std::endl;
      std::cout << "display: table-cell;" << std::endl;
      std::cout << "vertical-align:middle;" << std::endl;
      std::cout << "}" << std::endl;
      // white square
      std::cout << ".white {" << std::endl;
      std::cout << "width: 60px;" << std::endl;
      std::cout << "height: 60px;" << std::endl;
      std::cout << "background-color: #fffdd0;" << std::endl;
      std::cout << "font-size:50px;" << std::endl;
      std::cout << "text-align:center;" << std::endl;
      std::cout << "display: table-cell;" << std::endl;
      std::cout << "vertical-align:middle;" << std::endl;
      std::cout << "}" << std::endl;
      std::cout << "</style>" << std::endl;
      std::cout << "</head>" << std::endl;
      std::cout << "<body>" << std::endl;
      // place queens on n x n board
      composer.place_queens(0);
      std::cout << "<p>" << composer.get_total() << " solutions computed</p>" << std::endl;
   }
   std::cout << "</body>" << std::endl;
   std::cout << "</html>" << std::endl;
   return 0;
}

// get the step of the process
void readQueryString(char card[])
{
    strcpy(card, getenv("QUERY_STRING"));
}
