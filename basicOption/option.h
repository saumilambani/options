#ifndef OPTION_H
#define OPTION_H

class Option
{
   public:

   enum OptionType
   {
      CALL,
      PUT
   };
   
   Option(double strike, 
          double prem, 
          OptionType optionType):
          m_strike(strike), 
          m_prem(prem),
          m_optionType(optionType){}

   Option(const Option& opt):
      m_strike(opt.m_strike),
      m_prem(opt.m_prem),
      m_optionType(opt.m_optionType){}

   Option& operator=(const Option& opt)
   {
      if (this != &opt) 
      {
         m_strike = opt.m_strike;
         m_prem = opt.m_prem;
         m_optionType = opt.m_optionType;
      }
      return *this;
   }

   double optionValue(double spot)
   {
      double value = 0;
      if (m_optionType == CALL) 
      {
         if (spot > m_strike)
         {
            value = spot - m_strike; 
         }
      }
      else // PUT
      {
         if (m_strike > spot)
         {
           value = m_strike - spot;  
         }
      }
      return value;
   }

   double optionPnl(double spot)
   {
      double optionVal = optionValue(spot);
      return (optionVal - m_prem);
   }


   ~Option(){}

   private:
   double m_strike;
   double m_prem;
   OptionType m_optionType;

};

#endif // OPTION_H
