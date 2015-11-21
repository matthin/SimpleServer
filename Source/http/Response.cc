#include "Response.hh"

std::string ss::http::Response::as_string() const {
  std::string string_form;

  string_form.append(headers.at("protocol") + ' ')
      .append(headers.at("code") + ' ')
      .append(headers.at("code_message") + "\r\n");

  for (const auto &pair : headers) {
    const auto &key = pair.first;
    const auto &value = pair.second;

    if (key != "protocol" && key != "code" && key != "code_message") {
      string_form.append(key + ": " + value + "\r\n");
    }
  }

  if (!message.empty()) {
    string_form.append('\n' + message);
  }

  return string_form;
}
