// Copyright 2021 Trushkov Ilya ilya.tr20002@gmail.com
#include <stdexcept>

#include "Broker.hpp"

Broker::Broker(std::string &name, std::string &last_date, std::string &num_acc)
    : _name(name)
    , _last_date(last_date)
    , _num_account(num_acc) {}

void Broker::set_date(const std::string &date) {
  if (_last_date < date){
    _last_date = date;
  }
}

void Broker::operator++() {
  ++_num_files;
}

void Broker::print() {
  std::cout << "broker: " << _name << " number of accounts: "
            << _num_account << " number of files: "
            << _num_files << " last date: " << _last_date << std::endl;
}