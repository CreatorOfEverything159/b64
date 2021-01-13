#include <string>
#include "gtest/gtest.h"
#include "libBase64.h"

using namespace std;

TEST(encodeBase64, expectedTrueEncode) {
    string line = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut lab"
                  "ore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris n"
                  "isi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate veli"
                  "t esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, s"
                  "unt in culpa qui officia deserunt mollit anim id est laborum.";

    const char* expectedEncode = "TG9yZW0gaXBzdW0gZG9sb3Igc2l0IGFtZXQsIGNvbnNlY3RldHVyIGFkaXBpc2NpbmcgZWxpdCwgc2VkI"
                            "GRvIGVpdXNtb2QgdGVtcG9yIGluY2lkaWR1bnQgdXQgbGFib3JlIGV0IGRvbG9yZSBtYWduYSBhbGlxdW"
                            "EuIFV0IGVuaW0gYWQgbWluaW0gdmVuaWFtLCBxdWlzIG5vc3RydWQgZXhlcmNpdGF0aW9uIHVsbGFtY28"
                            "gbGFib3JpcyBuaXNpIHV0IGFsaXF1aXAgZXggZWEgY29tbW9kbyBjb25zZXF1YXQuIER1aXMgYXV0ZSBp"
                            "cnVyZSBkb2xvciBpbiByZXByZWhlbmRlcml0IGluIHZvbHVwdGF0ZSB2ZWxpdCBlc3NlIGNpbGx1bSBkb"
                            "2xvcmUgZXUgZnVnaWF0IG51bGxhIHBhcmlhdHVyLiBFeGNlcHRldXIgc2ludCBvY2NhZWNhdCBjdXBpZG"
                            "F0YXQgbm9uIHByb2lkZW50LCBzdW50IGluIGN1bHBhIHF1aSBvZmZpY2lhIGRlc2VydW50IG1vbGxpdCB"
                            "hbmltIGlkIGVzdCBsYWJvcnVtLg";

    ASSERT_STREQ(expectedEncode, encodingBase64(line).c_str());
}

TEST(decodeBase64, expectedTrueDecode) {
    string line = "TG9yZW0gaXBzdW0gZG9sb3Igc2l0IGFtZXQsIGNvbnNlY3RldHVyIGFkaXBpc2NpbmcgZWxpdCwgc2VkIGRvIGVpdXNtb2"
                  "QgdGVtcG9yIGluY2lkaWR1bnQgdXQgbGFib3JlIGV0IGRvbG9yZSBtYWduYSBhbGlxdWEuIFV0IGVuaW0gYWQgbWluaW0g"
                  "dmVuaWFtLCBxdWlzIG5vc3RydWQgZXhlcmNpdGF0aW9uIHVsbGFtY28gbGFib3JpcyBuaXNpIHV0IGFsaXF1aXAgZXggZW"
                  "EgY29tbW9kbyBjb25zZXF1YXQuIER1aXMgYXV0ZSBpcnVyZSBkb2xvciBpbiByZXByZWhlbmRlcml0IGluIHZvbHVwdGF0"
                  "ZSB2ZWxpdCBlc3NlIGNpbGx1bSBkb2xvcmUgZXUgZnVnaWF0IG51bGxhIHBhcmlhdHVyLiBFeGNlcHRldXIgc2ludCBvY2"
                  "NhZWNhdCBjdXBpZGF0YXQgbm9uIHByb2lkZW50LCBzdW50IGluIGN1bHBhIHF1aSBvZmZpY2lhIGRlc2VydW50IG1vbGxp"
                  "dCBhbmltIGlkIGVzdCBsYWJvcnVtLg";

    const char* expectedDecodeLine = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor i"
                                     "ncididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostru"
                                     "d exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aut"
                                     "e irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat n"
                                     "ulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui"
                                     " officia deserunt mollit anim id est laborum.";

    ASSERT_STREQ(expectedDecodeLine, decodingBase64(line).c_str());
}

TEST(encodeRusBase64, expectedTrueRusDecode) {
    string line = "Съешь ещё этих мягких французских булок да выпей чаю!";

    const char* expectedDecodeLine = "0KHRitC10YjRjCDQtdGJ0ZEg0Y3RgtC40YUg0LzRj9Cz0LrQuNGFINGE0YDQsNC90YbRg9C30YHQutC4"
                                     "0YUg0LHRg9C70L7QuiDQtNCwINCy0YvQv9C10Lkg0YfQsNGOIQ";

    ASSERT_STREQ(expectedDecodeLine, encodingBase64(line).c_str());
}

TEST(decodeRusBase64, expectedTrueRusDecode) {
    string line = "0KHRitC10YjRjCDQtdGJ0ZEg0Y3RgtC40YUg0LzRj9Cz0LrQuNGFINGE0YDQsNC90YbRg9C30YHQutC4"
                  "0YUg0LHRg9C70L7QuiDQtNCwINCy0YvQv9C10Lkg0YfQsNGOIQ";

    const char* expectedDecodeLine = "Съешь ещё этих мягких французских булок да выпей чаю!";

    ASSERT_STREQ(expectedDecodeLine, decodingBase64(line).c_str());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
