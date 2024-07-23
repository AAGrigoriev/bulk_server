#include "server.hpp"

#include <memory>

#include "session.hpp"

namespace network {

server::server(asio::io_context& io_context,
               const asio::ip::tcp::endpoint& endpoint,
               std::size_t bulk_size)
    : acceptor_(io_context, endpoint), bulk_size_(bulk_size) {}

void server::do_accept() {
  acceptor_.async_accept(
      [this](boost::system::error_code ec, asio::ip::tcp::socket socket) {
        if (!ec) {
          std::make_shared<session>(bulk_size_, std::move(socket));
        }
        do_accept();
      });
}

}  // namespace network
