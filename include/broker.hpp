// Copyright 2021 Melnikova Maria dandelion.m@mail.ru
#ifndef INCLUDE_BROKER_HPP_
#define INCLUDE_BROKER_HPP_

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

#endif  // INCLUDE_BROKER_HPP_
