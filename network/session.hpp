#pragma once

#include <array>
#include <cstddef>
#include <memory>

#include <boost/asio.hpp>

namespace network {

namespace asio = boost::asio;

class session : std::enable_shared_from_this<session> {
 public:
  session(std::size_t bulk_size, asio::ip::tcp::socket&& socket);

  void start();

 private:
  void do_read();

 private:
  static constexpr std::size_t BUFFER_SIZE = 1024;
  std::size_t bulk_size_;
  asio::ip::tcp::socket socket_;
  std::array<char, BUFFER_SIZE> buffer_;
};

}  // namespace network
