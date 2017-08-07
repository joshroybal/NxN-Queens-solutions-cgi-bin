#ifndef QCLASS_HPP__
#define QCLASS_HPP__

class queens_on_board   {
   public:
      queens_on_board(int); // default constructor
      int check_square(int, int); // checks for legal placement
      void place_queens(int); // drop in replacement for above
      void update_status_html(); // 3rd millennium version
      int get_total() { return total; } // public access function
   private:
      int size; // user choice of N
      int total; // number of positions for N x N
      int queen_vector[10]; // queen position array
};

#endif
