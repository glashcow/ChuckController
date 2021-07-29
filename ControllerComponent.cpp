/*
  ==============================================================================

    ControllerComponent.cpp
    Created: 1 Jul 2021 00:12:27am
    Author:  ewana

  ==============================================================================
*/

#include "ControllerComponent.h"

OscManager::OscManager(short port) {
    sender.connect(LOCALHOST, port);
}

OscManager::~OscManager() {
    childProcess.kill();
    sender.disconnect();
}

void OscManager::turnChuckOn()
{
    childProcess.start(command);
}

void OscManager::turnChuckOff() 
{
    childProcess.kill();
}

void OscManager::setCommand(LPSTR command) {
    this->command = command;
}

void OscManager::setAddressPattern(juce::String address) {
    this->addressPattern = address;
}

void OscManager::send(float signal) {
    sender.send((juce::OSCAddressPattern)addressPattern, signal);
}

void OscManager::kill() {
    childProcess.kill();
}



/*====================================================================================
=======================================================================================*/



ControllerComponent::~ControllerComponent() 
{
    oscManager->kill();
}


void ControllerComponent::clickChuckToggle()
{
    toggleOn = !toggleOn;
    if (toggleOn) {
        oscManager->turnChuckOn();
        chuckToggle.setColour(1,juce::Colour(34, 230, 21));
    }
    else {
        oscManager->turnChuckOff();
        chuckToggle.setColour(1, juce::Colour(34, 90, 21));
    }
    
}

void ControllerComponent::standardToggle(const juce::String label) {
    addAndMakeVisible(chuckToggle);
    chuckToggle.setButtonText(label);
    chuckToggle.setBounds(50, 200, 100, 200);
    chuckToggle.onClick = [this] {
        clickChuckToggle();
    };
}

void ControllerComponent::standardKnob(double min, double max) {
    rotaryKnob.setRange(min, max);
    rotaryKnob.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    rotaryKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 150, 25);
    rotaryKnob.setBounds(50, 50, 100, 180);
    addAndMakeVisible(rotaryKnob);

    rotaryKnob.onValueChange = [this] {
        oscManager->send((float)rotaryKnob.getValue());
    };
}


