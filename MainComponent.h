#pragma once

#include <JuceHeader.h>
#include <windows.h>

#include "FrequencyDestructorComponent.h"

//==============================================================================
/*
    To debug you need to do this 

    std::ofstream file("someFileName.txt");
    file << command;
    file.close();
    (obvs will put whatever string [oderwas] into that file)

    Then the file will be in D:\Master Dev Folder\CPP\JUCE Projects\ChuckControl\Builds\VisualStudio2019
*/


class MainComponent  : public juce::AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;


private:
    FrequencyDestructorComponent frequencyDestructorComponent;

   JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

