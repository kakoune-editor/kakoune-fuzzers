#include <string.hh>
#include <regex.hh>
#include <exception.hh>

using namespace Kakoune;

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    String data_str{(const char*)data, (ByteCount)size};

    try
    {
        MatchResults<String::iterator> matches;
        Regex re = Regex(data_str);
        regex_match(data_str.begin(), data_str.end(), matches, re);
    }
    catch (runtime_error&) {}

    return 0;
}
