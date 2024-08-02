#include <iostream>

#include <boost/asio.hpp>

#include "command_parser.hpp"
#include "server.hpp"

using boost::asio::ip::tcp;

int main(int argc, char* argv[]) try {
  command_parser::parser_output context;
  try {
    context = command_parser::parse(argc, argv);
  } catch (...) {
    return 0;
  }

  boost::asio::io_service io_context;

  network::server server(io_context, context.endpoint, context.bulk_size);

  io_context.run();

  return 0;

} catch (const std::exception& e) {
  std::cerr << e.what() << '\n';
  return 1;
}
