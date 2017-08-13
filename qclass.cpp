#include <iostream>
#include <cstdlib>
#include "qclass.hpp"

const int TRUE = 1;
const int FALSE = 0;

queens_on_board::queens_on_board(int n)
{
   total = 0;
   size = n;
   for (int i = 0; i < size; i++)
      queen_vector[i] = 0;
}

int queens_on_board::check_square(int row, int col)
{
   int result = TRUE;

   if (row < 0 || col < 0 || col > size - 1 || row > size - 1)
      result = FALSE;

   if (row == 0 && col == 0)
      result = TRUE;
   else
      for (int i = 0; i < col && result != FALSE; i++)
         if (row == queen_vector[i] || row == queen_vector[i] + (col - i)
            || row == queen_vector[i] - (col - i))
               result = FALSE;

   return result;
}

// core recursive subroutine
void queens_on_board::place_queens(int k)
{
   if (k == size) {
      total++;
      update_status_html();
   }
   else {
      for (int i = 0; i < size; i++) {
         if (check_square(i, k) == true) {
            queen_vector[k] = i;
            place_queens(k + 1);
         }
      }
   }
}

// places queens on board as instances are popped off the processor stack
void queens_on_board::update_status_html()
{
   int board_dim = size * 60;
   std::string color = "black";
   std::cout << "<div>board position " << total << "</div>" << std::endl;
   std::cout << "<table class=\"chessboard\">" << std::endl;
   for (int row = 0; row < size; row++)   {
      std::cout << "<tr>";
      for (int col = 0; col < size; col++) {
         if ((row + col) % 2 == 0)
            color = "\"white\"";
         else
            color = "\"black\"";
         if (col == queen_vector[row])
            std::cout << "<td class=" << color << ">&#9819;</td>";
         else
            std::cout << "<td class=" << color << "></td>";
      }
      std::cout << "</tr>" << std::endl;
   }
   std::cout << "</table>" << std::endl;
}
