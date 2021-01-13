#ifndef CRYPTBASE64_LIBBASE64_H
#define CRYPTBASE64_LIBBASE64_H
#include <string>

std::string encodingBase64(const std::string &line);
std::string decodingBase64(const std::string &line);

#endif //CRYPTBASE64_LIBBASE64_H
