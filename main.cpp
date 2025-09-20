/**
 * @brief Lequel? main module
 * @author Marc S. Ressl
 * 
 * @copyright Copyright (c) 2022-2023
 */

#include <iostream>
#include <map>
#include <string>
#include <filesystem>

#include "raylib.h"

#include "CSVData.h"
#include "Lequel.h"

#define DEBUG 0
#define SEPARATOR "_"

using namespace std;

const string LANGUAGECODE_NAMES_FILE = "resources/languagecode_names_es.csv";
const string TRIGRAMS_PATH = "resources/trigrams/";
const string TEXTS_PATH = "resources/texts/";

static CSVData profileToCSV(TrigramProfile& profile);
static bool loadCustomLanguages(const string PATH);
static bool loadLanguagesData(map<string, string>& languageCodeNames, LanguageProfiles& languages);


// Converts a trigram profile list<string, float> to a CSVData vector<>
static CSVData profileToCSV(TrigramProfile &profile)
{
    CSVData result;
    for (auto& trigram : profile) 
    {
        result.push_back({trigram.first, to_string((int)trigram.second)});
    }
    return result;
}

/**
 * @brief Loads trigram data.
 * 
 * @param languageCodeNames Map of language code vs. language name (in i18n locale).
 * @param languages The trigram profiles.
 * @return true Succeeded
 * @return false Failed
 */
static bool loadLanguagesData(map<string, string> &languageCodeNames, LanguageProfiles &languages)
{
    // Reads available language codes
    cout << "Reading language codes..." << endl;

    CSVData languageCodesCSVData;
    if (!readCSV(LANGUAGECODE_NAMES_FILE, languageCodesCSVData))
        return false;

    // Reads trigram profile for each language code
    for (auto &fields : languageCodesCSVData)
    {
        if (fields.size() != 2)
            continue;

        string languageCode = fields[0];
        string languageName = fields[1];

        languageCodeNames[languageCode] = languageName;

        cout << "Reading trigram profile for language code \"" << languageCode << "\"..." << endl;

        CSVData languageCSVData;
        if (!readCSV(TRIGRAMS_PATH + languageCode + ".csv", languageCSVData))
            return false;

        languages.push_back(LanguageProfile());
        LanguageProfile &language = languages.back();

        language.languageCode = languageCode;

        for (auto &fields : languageCSVData)
        {
            if (fields.size() != 2)
                continue;

            string trigram = fields[0];
            float frequency = (float)stoi(fields[1]);

            language.trigramProfile[trigram] = frequency;
        }

        normalizeTrigramProfile(language.trigramProfile);
    }

    return true;
}

/*
* @brief generates trigrams for custom language from corpus
* @param PATH string containing the path to the corpus texts
* @return true succeded
* @return false failed
*/
static bool loadCustomLanguages(const string PATH)
{
    if (!filesystem::exists(PATH) || !filesystem::is_directory(PATH))
        return false;

    for (auto& file : filesystem::directory_iterator(PATH)) 
    {
        filesystem::path filePath = file.path();
        string fileName = filePath.filename().stem().string();
        size_t pos = fileName.find(SEPARATOR);
        
        // Get the data from the file name format: "languageCode_languageName"
        string languageCode, languageName;
        if (pos != string::npos)
        {
            languageCode = fileName.substr(0, pos);
            languageName = fileName.substr(pos + 1);
        }

        if (!languageCode.length() || !languageName.length())
            return false;
        
        // Skip any existing language.
        string csvFile = TRIGRAMS_PATH + languageCode + ".csv";
        if (filesystem::exists(csvFile))
            continue;

        cout << "Loading custom language: " << languageName << endl;

        Text data;
        getTextFromFile(filePath.string(), data);
        TrigramProfile languageProfile = buildTrigramProfile(data);
        CSVData languageData = profileToCSV(languageProfile);
        writeCSV(csvFile, languageData);

        // Update language code names csv file
        CSVData languageCodes;
        readCSV(LANGUAGECODE_NAMES_FILE, languageCodes);
        languageCodes.push_back({ languageCode, languageName });
        writeCSV(LANGUAGECODE_NAMES_FILE, languageCodes);
    }
    return true;
}

int main(int argc, char *argv[])
{
    map<string, string> languageCodeNames;
    LanguageProfiles languages;

    loadCustomLanguages(TEXTS_PATH);

    if (!loadLanguagesData(languageCodeNames, languages))
    {
        cout << "Could not load trigram data." << endl;
        return 1;
    }

    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Lequel?");

    SetTargetFPS(60);

    string languageCode = "---";

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_V) &&
            (IsKeyDown(KEY_LEFT_CONTROL) ||
             IsKeyDown(KEY_RIGHT_CONTROL) ||
             IsKeyDown(KEY_LEFT_SUPER) ||
             IsKeyDown(KEY_RIGHT_SUPER)))
        {
            const char *clipboard = GetClipboardText();

            Text text;
            getTextFromString(clipboard, text);

            languageCode = identifyLanguage(text, languages, DEBUG);
        }

        if (IsFileDropped())
        {
            FilePathList droppedFiles = LoadDroppedFiles();

            if (droppedFiles.count == 1)
            {
                Text text;
                getTextFromFile(droppedFiles.paths[0], text);

                languageCode = identifyLanguage(text, languages, DEBUG);

                UnloadDroppedFiles(droppedFiles);
            }
        }

        BeginDrawing();

        ClearBackground(BEIGE);

        DrawText("Lequel?", 80, 80, 128, BROWN);
        DrawText("Copia y pega con Ctrl+V, o arrastra un archivo...", 80, 220, 24, BROWN);

        string languageString;
        if (languageCode != "---")
        {
            if (languageCodeNames.find(languageCode) != languageCodeNames.end())
                languageString = languageCodeNames[languageCode];
            else
                languageString = "Desconocido";
        }

        int languageStringWidth = MeasureText(languageString.c_str(), 48);
        DrawText(languageString.c_str(), (screenWidth - languageStringWidth) / 2, 315, 48, BROWN);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
