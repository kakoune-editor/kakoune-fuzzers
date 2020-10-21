#include <string.hh>
#include <diff.hh>

using namespace Kakoune;

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    StringView reference_str = "Quos animi ut officia quia. Iste ut quisquam placeat quia. Exercitationem culpa et placeat et aut enim.";
    String data_str{(const char*)data, (ByteCount)size};

    for_each_diff(data_str.begin(), (int)data_str.length(), reference_str.begin(), (int)reference_str.length(), [](DiffOp, int){});

    return 0;
}
