#pragma once

#include <memory>
#include <unordered_set>

#include "command.hpp"
#include "i_writer.hpp"

namespace logic {

class post_processor {
 public:
  void add_writer(std::unique_ptr<i_writer> writer);

  void process_data(std::shared_ptr<const command> data) const;

 private:
  std::unordered_set<std::unique_ptr<i_writer>> writers_;
};

}  // namespace logic
