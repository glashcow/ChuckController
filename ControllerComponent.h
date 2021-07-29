/*
  ==============================================================================

    ControllerComponent.h
    Created: 1 Jul 2021 00:12:27am
    Author:  ewana

  ==============================================================================
*/
#pragma once

#include <JuceHeader.h>
#include <windows.h>

std::string static LOCALHOST = "127.0.0.1";
std::string static CHUCK_COMMAND_WITH_DIRECTORY = "chuck \"D:/Master Dev Folder/CPP/JUCE Projects/ChuckControl/ChuckJuce";
short static componentCount = 0;


class OscManager {
public:

    OscManager(short port);
    ~OscManager();

    void turnChuckOn();

    void turnChuckOff();

    void setCommand(LPSTR command);

    void setAddressPattern(juce::String address);

    void send(float signal);

    void kill();

private:
    juce::ChildProcess childProcess;
    juce::OSCSender sender;
    juce::String addressPattern;
    LPSTR command;
};


/*
+++++++++++++++++++++++++++++++++++===================++++++++++++++++++++++++
+++++++++++++++++++++++++++++++++++===================++++++++++++++++++++++++
*/


class ControllerComponent : public juce::Component {
public:

    ControllerComponent() {};

    ~ControllerComponent();

    void clickChuckToggle();

    void setPort(short port) {
        oscManager = new OscManager(port);
    }

    virtual void createToggle() {};

    virtual void createKnob() {};

    void standardToggle(const juce::String label);

    void standardKnob(double min, double max);

protected:
    juce::TextButton chuckToggle;
    juce::Slider rotaryKnob;
    bool toggleOn = false;
    
    OscManager *oscManager;
};


