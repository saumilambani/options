#include "option.h"
#include <iostream>

int main()
{
   Option option(100.0, 1.1 , Option::PUT);
   double optVal = 0;
   double optPnl = 0;

   double spot1 = 120.0;
   optVal = option.optionValue(spot1);
   optPnl = option.optionPnl(spot1);
   std::cout << " For Put: spot 120 value " << optVal  << " and pnl " << optPnl << std::endl;

   double spot2 = 85.0;
   optVal = option.optionValue(spot2);
   optPnl = option.optionPnl(spot2);
   std::cout << " For Put: spot 85 value " << optVal  << " and pnl " << optPnl << std::endl;

   Option option1(100.0, 1.1 , Option::CALL);

   spot1 = 120.0;
   optVal = option1.optionValue(spot1);
   optPnl = option1.optionPnl(spot1);
   std::cout << " For Call: spot 120 value " << optVal  << " and pnl " << optPnl << std::endl;

   spot2 = 85.0;
   optVal = option1.optionValue(spot2);
   optPnl = option1.optionPnl(spot2);
   std::cout << " For Call: spot 85 value " << optVal  << " and pnl " << optPnl << std::endl;
}

