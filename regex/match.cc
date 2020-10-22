#include <fuzzer/FuzzedDataProvider.h>

#include <string.hh>
#include <regex.hh>
#include <exception.hh>

using namespace Kakoune;

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider fuzzed_data(data, size);

    const size_t regex_length = fuzzed_data.ConsumeIntegral<uint8_t>();
    const std::string regex_string = fuzzed_data.ConsumeBytesAsString(regex_length);
    const std::string text_string = fuzzed_data.ConsumeRemainingBytesAsString();

    try
    {
        StringView text = {text_string.c_str(), text_string.length()};
        MatchResults<String::const_iterator> matches;
        Regex regex = Regex({regex_string.c_str(), regex_string.length()});
        regex_match(text.begin(), text.end(), matches, regex);
    }
    catch (runtime_error&) {}

    return 0;
}
