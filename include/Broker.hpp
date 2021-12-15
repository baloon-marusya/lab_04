// Copyright 2021 Trushkov Ilya ilya.tr20002@gmail.com
#ifndef TEMPLATE_BROKER_HPP
#define TEMPLATE_BROKER_HPP

#include <iostream>
#include <regex>
#include <string>
#include "boost/filesystem.hpp"

namespace fs = boost::filesystem;

class Broker {
 private:
  std::string _name;
  std::string _last_date;
  std::string _num_account;
  int _num_files = 0;

 public:
  Broker(std::string& name, std::string& last_date, std::string& num_acc);
  void set_date(const std::string &date);
  void operator++();
  void print();
};

#endif  // TEMPLATE_BROKER_HPP
