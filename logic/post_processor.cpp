#include "post_processor.hpp"

#include <sstream>

namespace logic {

void post_processor::add_console_writer(std::unique_ptr<i_writer> writer) {
  console_writer_ = std::move(writer);
}

void post_processor::add_file_writer(std::unique_ptr<i_writer> writer) {
  file_writer_ = std::move(writer);
}

void post_processor::process_data(const command& command) const {
  for (const auto& writer : writers_) {
    writer->write(buffer);
  }
}

}  // namespace logic
