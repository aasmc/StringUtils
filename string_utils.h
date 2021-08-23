#pragma once

#include "iterator_range.h"

#include <string_view>
#include <sstream>
#include <vector>
#include "optional"

template <typename Container>
std::string Join(char c, const Container& cont) {
    std::ostringstream os;
    for (const auto& item : Head(cont, cont.size() - 1)) {
        os << item << c;
    }
    os << *std::rbegin(cont);
    return os.str();
}

std::string_view Strip(std::string_view s);
std::vector<std::string_view> SplitBy(std::string_view s, char sep);
void LeftStrip(std::string_view& sv);
std::string_view ReadTokenSpaceDelim(std::string_view& sv);

std::vector<std::string_view> SplitIntoWordsView(std::string_view str);

std::pair<std::string_view, std::optional<std::string_view>> SplitTwoStrict(std::string_view s, std::string_view delimiter = " ");

std::pair<std::string_view, std::string_view> SplitTwo(std::string_view s, std::string_view delimiter = " ");

std::string_view ReadToken(std::string_view& s, std::string_view delimiter = " ");

int ConvertToInt(std::string_view str);