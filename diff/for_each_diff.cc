#include <fuzzer/FuzzedDataProvider.h>

#include <string.hh>
#include <diff.hh>

using namespace Kakoune;

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider fuzzed_data(data, size);

    const size_t regex_length = fuzzed_data.ConsumeIntegral<uint8_t>();
    const std::string reference_string = fuzzed_data.ConsumeBytesAsString(regex_length);
    const std::string text_string = fuzzed_data.ConsumeRemainingBytesAsString();

    {
        StringView reference = {reference_string.c_str(), reference_string.length()};
        StringView text = {text_string.c_str(), text_string.length()};
        for_each_diff(text.begin(), (int)text.length(),
                      reference.begin(), (int)reference.length(),
                      [](DiffOp, int){});
    }

    return 0;
}
