#ifndef SESSION_DEFINED
#define SESSION_DEFINED

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <vector>
#include <map>
// for tcp type
using boost::asio::ip::tcp;

class session
{
public:
  session(boost::asio::io_service& io_service, std::map <std::string, std::string> function_mapping);
  tcp::socket& socket();
  void start();
  int handle_write(const boost::system::error_code& error, size_t bytes_transferred);
  void setup_obuffer(boost::asio::streambuf& out_streambuf, size_t bytes_transferred);
  int handle_request(const boost::system::error_code& error, size_t bytes_transferred);

private:
  std::vector<char> convert_buffer();
  std::string get_function_from_url(std::string url);
  std::string get_doc_root_from_url(std::string url);
  tcp::socket socket_;
  std::map <std::string, std::string> function_mapping;
  boost::asio::streambuf buffer;
};

#endif
