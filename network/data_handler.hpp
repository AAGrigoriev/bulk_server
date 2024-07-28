#pragma once

#include <algorithm>
#include <array>
#include <sstream>
#include <string>

#include "controller.hpp"

namespace network {

class data_handler {
 public:
  data_handler(std::size_t bulk_size);

  template <std::size_t SIZE>
  void recieve(std::array<char, SIZE>& array, std::size_t real_length);

 private:
  std::string buffer_;
  logic::controller controller_;
};

template <std::size_t SIZE>
void data_handler::recieve(std::array<char, SIZE>& array,
                           std::size_t real_length) {
  if (auto it = std::find(std::rbegin(array), std::rend(array), '\n');
      it == array.rend()) {
    buffer_.append(array.begin(), array.end());
    return;
  } else {
    std::istringstream stream(buffer_ +
                              std::string(array.begin(), array.begin() + it));
  }
}

}  // namespace network
