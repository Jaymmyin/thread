#ifndef CP5_CH14_EX14_02_H
#define CP5_CH14_EX14_02_H

#include <string>
#include <iostream>

class Sales_data{
  friend std::istream& operator>>(std::istream&, Sales_data&);
  friend std::ostream& operator<<(std::ostream&, const Sales_data&);
  friend Sales_data operator+(const Sales_data&, const Sales_data&);

public:
  Sales_data(const std::string& s, unsigned n, double p):
    bookNo(s), units_sold(n), revenue(p){}
  Sales_data():Sales_data("",0, 0.0f){}
  Sales_data(std::istream&);

  Sales_data& operator+=(const Sales_data&);
  std::string isbn() const {return bookNo;}
private:

  inline double avg_price() const;
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};


std::istream& operator>>(std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

inline double Sales_data::avg_price() const {
  return units_sold ? revenue / units_sold : 0;
}



#endif // CP5_CH14_EX14_02_H
