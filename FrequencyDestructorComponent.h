/*
  ==============================================================================

    FrequencyDestructorComponent.h
    Created: 1 Jul 2021 10:53:22pm
    Author:  ewana

  ==============================================================================
*/

#pragma once

#include "ControllerComponent.h"

class FrequencyDestructorComponent : public ControllerComponent {
public:
    FrequencyDestructorComponent();

    void createToggle();

    void createKnob();
};