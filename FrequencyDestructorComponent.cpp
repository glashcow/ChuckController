/*
  ==============================================================================

    FrequencyDestructorComponent.cpp
    Created: 1 Jul 2021 10:53:22pm
    Author:  ewana

  ==============================================================================
*/
#include "FrequencyDestructorComponent.h"

FrequencyDestructorComponent::FrequencyDestructorComponent() : ControllerComponent(){
    componentCount++;
    setSize(500, 500);
    setPort(1234);
    oscManager->setCommand("chuck \"D:/Master Dev Folder/CPP/JUCE Projects/ChuckControl/Source/ChuckJuce/oscChuck.ck\"");
    oscManager->setAddressPattern("/freq");
    createToggle();
    createKnob();
}

void FrequencyDestructorComponent::createToggle() {
    standardToggle("Frequency Slider to Hell");
}

void FrequencyDestructorComponent::createKnob() {
    standardKnob(0.5, 1.9);
}