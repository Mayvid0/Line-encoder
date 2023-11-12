#include <iostream>
#include "openWindow.h"
#include <fstream>
#include <vector>
#include <cstdint>
#include <random>
#include <ctime>
#include <bitset>
using namespace std;

vector<std::bitset<16>> pcmSample(bool pcmOrDm)
{
    // Read WAV file
    std::ifstream file("assets/1.wav", std::ios::binary);

    if (!file.is_open())
    {
        std::cerr << "Error opening the file" << std::endl;
    }

    // Read WAV header (assuming a simple WAV file with a 44-byte header)
    const int headerSize = 44;
    file.seekg(0, std::ios::end);
    int fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Check if the file is large enough to contain a header
    if (fileSize < headerSize)
    {
        std::cerr << "Invalid WAV file" << std::endl;
    }

    // Skip the header
    file.seekg(headerSize, std::ios::beg);

    // Read only the first 10 PCM samples
    const int numSamplesToRead = 40;
    std::vector<int16_t> pcmData(numSamplesToRead);
    file.read(reinterpret_cast<char *>(pcmData.data()), numSamplesToRead * sizeof(int16_t));

    std::vector<int16_t> deltaModulatedData(numSamplesToRead);
    deltaModulatedData[0] = pcmData[0]; // First sample remains unchanged

    for (int i = 1; i < numSamplesToRead; ++i)
    {
        deltaModulatedData[i] = pcmData[i] - pcmData[i - 1];
    }

    file.close();

    std::vector<std::bitset<16>> binaryPcm;
    std::vector<std::bitset<16>> binaryDm;

    for (int16_t sample : pcmData)
    {
        // Convert each 16-bit sample to a binary sequence (assuming 16 bits per sample)
        bitset<16> binarySample(sample);
        binaryPcm.push_back(binarySample);
    }

    for (int16_t sample1 : deltaModulatedData)
    {
        // Convert each 16-bit sample to a binary sequence (assuming 16 bits per sample)
        bitset<16> binarySample1(sample1);
        binaryDm.push_back(binarySample1);
    }

    if (pcmOrDm == true)
        return binaryPcm;
    else
        return binaryDm;
}

void handleAnalogOption()
{
    vector<std::bitset<16>> pcmData = pcmSample(true);
    vector<std::bitset<16>> dmData = pcmSample(false);

    cout << "What Do you want to perform:  \n";
    cout << "1. PCM\n";
    cout << "2. DM\n";
    int pcm_dm;
    cin >> pcm_dm;

    cout << " The analog wave produces the following sampled data :\n";
    if (pcm_dm == 1)
    {
        for (bitset<16> sample : pcmData)
        {
            cout << sample << endl;
        }
    }
    else
    {
        for (bitset<16> sample : dmData)
        {
            cout << sample << endl;
        }
    }

    cout << "Do you want to perform line encoding on any one of these samples? \n";
    cout << "1. Yes\n";
    cout << "2. No \n";
    int choice3;
    cin >> choice3;

    if (choice3 == 1)
    {
        if (pcm_dm == 1)
        {
            std::mt19937 gen(static_cast<unsigned>(time(0)));
            std::uniform_int_distribution<size_t> distribution(0, pcmData.size() - 1);
            size_t randomIndex = distribution(gen);
            std::bitset<16> randomSample = pcmData[randomIndex];
            std::string binaryString = randomSample.to_string();
            handleDigitalOption(binaryString);
        }
        else
        {
            std::mt19937 gen(static_cast<unsigned>(time(0)));
            std::uniform_int_distribution<size_t> distribution(0, dmData.size() - 1);
            size_t randomIndex = distribution(gen);
            std::bitset<16> randomSample = dmData[randomIndex];
            std::string binaryString = randomSample.to_string();
            handleDigitalOption(binaryString);
        }
    }
    else
    {
        return;
    }

    return;
}
