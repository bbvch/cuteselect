#
# (C) Copyright 2016
# Urs Fässler, bbv Software Services, http://bbv.ch
#
# SPDX-License-Identifier:	GPL-3.0+
#

# language: en

Feature: Configure the application
  As a system integrator
  I want to specify the visual appearance of the application
  In order to fit the application into the design

Scenario: Use a color for the background
  Given I have the following configuration file:
    """
    <cuteselect background-color="#041233" />
    """

  When I start the application

  Then I expect the property backgroundColor to be "#041233"

Scenario: Use the default color for the background
  Given I have the following configuration file:
    """
    <cuteselect />
    """

  When I start the application

  Then I expect the property backgroundColor to be "#000000"

Scenario: Use a default relative width for the items
  Given I have the following configuration file:
    """
    <cuteselect />
    """

  When I start the application

  Then I expect the property relativeWidth to be the number 0.25

Scenario: Specify the relative width for the items
  Given I have the following configuration file:
    """
    <cuteselect relative-width="0.1234" />
    """

  When I start the application

  Then I expect the property relativeWidth to be the number 0.1234

Scenario: Use a default relative height for the items
  Given I have the following configuration file:
    """
    <cuteselect />
    """

  When I start the application

  Then I expect the property relativeHeight to be the number 0.5

Scenario: Specify the relative height for the items
  Given I have the following configuration file:
    """
    <cuteselect relative-height="0.9876" />
    """

  When I start the application

  Then I expect the property relativeHeight to be the number 0.9876

Scenario: Use a default relative text height for the items
  Given I have the following configuration file:
    """
    <cuteselect />
    """

  When I start the application

  Then I expect the property relativeTextHeight to be the number 0.1

Scenario: Specify the relative height for the items
  Given I have the following configuration file:
    """
    <cuteselect relative-text-height="0.2" />
    """

  When I start the application

  Then I expect the property relativeTextHeight to be the number 0.2

