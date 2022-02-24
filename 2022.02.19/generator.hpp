#pragma once

#include < unordered_set >
#include < string >
#include < random >
#include < chrono >

std::unordered_set < std::string > make_random_words(size_t N, size_t length = 10U)
{
    std::uniform_int_distribution <> letter(97, 122);
    std::mt19937 e(static_cast < size_t > (
        std::chrono::system_clock::now().time_since_epoch().count()));

    std::unordered_set < std::string > words;

    for (std::string s(length, '_'); std::size(words) < N; words.insert(s))
        for (auto & c : s)
            c = letter(e);

    return words;
}