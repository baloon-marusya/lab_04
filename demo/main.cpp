#include "broker.hpp"

int main(int argc, char* argv[]) {
  fs::path path_to_ftp;
  if (argc < 2) {
    path_to_ftp = fs::current_path();
  } else {
    path_to_ftp = argv[1];
  }

  const std::regex balance_file{"balance_[0-9]{8}_[0-9]{8}\\.txt"};
  std::map<std::string, Broker> brokers;

  for (const auto& path : fs::recursive_directory_iterator(path_to_ftp)) {
    auto filename = path.path().filename();

    auto broker_name = path.path().parent_path().filename().string();

    if (fs::is_regular_file(path) &&
        std::regex_match(filename.string(), balance_file)) {
      std::cout << filename.string() << std::endl;
      std::string date = filename.string();
      date.erase(0, 17);
      date.erase(8, 4);

      std::string num_account = filename.string();
      num_account.erase(0, 8);
      num_account.erase(8, 13);
      if (!brokers.count(broker_name)) {
        Broker broker(broker_name, date, num_account);
        brokers.insert({broker_name, broker});
      } else {
        brokers.at(broker_name).set_date(date);
        ++brokers.at(broker_name);
      }
    }
  }
  for (auto &broker : brokers) {
    broker.second.print(); 
  }
  return 0;
}