/**
 * @brief Lequel? language identification based on trigrams
 * @author Marc S. Ressl
 *
 * @copyright Copyright (c) 2022-2023
 *
 * @cite https://towardsdatascience.com/understanding-cosine-similarity-and-its-application-fd42f585296a
 */

#include <cmath>
#include <codecvt>
#include <locale>
#include <iostream>

#include "Lequel.h"

using namespace std;

/**
 * @brief Builds a trigram profile from a given text.
 *
 * @param text Vector of lines (Text)
 * @return TrigramProfile The trigram profile
 */
TrigramProfile buildTrigramProfile(const Text &text)
{
    wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    TrigramProfile profile;
    for (auto line : text)
    {
        if (line.length() > 0) {
            if (line[line.length() - 1] == '\r') {
                line = line.substr(0, line.length() - 1);
            }
            wstring unicodeString = converter.from_bytes(line);
            
            if (unicodeString.length() < 3)
                continue;
            
            for (int i = 0; i < unicodeString.length()-3; i++) {
                string trigram = converter.to_bytes(unicodeString.substr(i, 3)); // Checks every posible trigram.
                profile[trigram]++; // increments absolute frequency of found trigram (creates the trigram if it doesn't exist).
            }
        } 
    }

    return profile;
}

/**
 * @brief Normalizes a trigram profile.
 *
 * @param trigramProfile The trigram profile.
 */
void normalizeTrigramProfile(TrigramProfile &trigramProfile)
{
    float squareSum = 0.0f;
    for (auto& element : trigramProfile) {
        squareSum += element.second * element.second;
    }
    float squareSum_root = sqrt(squareSum);
    for (auto& element : trigramProfile) {
        element.second /= squareSum_root;
    }
    return;
}

/**
 * @brief Calculates the cosine similarity between two trigram profiles
 *
 * @param textProfile The text trigram profile
 * @param languageProfile The language trigram profile
 * @return float The cosine similarity score
 */
float getCosineSimilarity(TrigramProfile &textProfile, TrigramProfile &languageProfile, unsigned &numberOfTrigramsMatch, TrigramMatches &tMatches)
{
    tMatches.clear();
    float score = 0;
    for (auto &element : textProfile) {
        if (languageProfile.find(element.first) != languageProfile.end()) {
            score += element.second * languageProfile[element.first];
            numberOfTrigramsMatch++;
            tMatches.push_back(element.first);
        }
    }
    return score;
}

/**
 * @brief Identifies the language of a text.
 *
 * @param text A Text (vector of lines)
 * @param languages A list of Language objects
 * @return string The language code of the most likely language
 */
string identifyLanguage(const Text &text, LanguageProfiles &languages, bool debug)
{
    string language_code_best;
    float cosine_score_best = 0.0f;
    TrigramProfile text_profile = buildTrigramProfile(text);
    normalizeTrigramProfile(text_profile);
    for (auto &language : languages) {
        unsigned trigramMatchesNum = 0;
        TrigramMatches trigramMatches;
        float score = getCosineSimilarity(text_profile, language.trigramProfile, trigramMatchesNum, trigramMatches);
        if (debug)
        {
            if (language.languageCode == "eng" || language.languageCode == "afr") // "gla"
            {
                cout << "Cosine similarity with " << language.languageCode << ": " << score << endl;
                cout << "Number of trigram matches: " << trigramMatchesNum << endl;
                cout << "Trigram matches: {" << endl;
                for (auto& trig : trigramMatches)
                    cout << trig << " | Frequency: " << language.trigramProfile[trig] << endl;
                cout << "}" << endl;
            }
        }
        if (score > cosine_score_best) 
        {
            cosine_score_best = score;
            language_code_best = language.languageCode;
        }
    }

    return language_code_best;
}
