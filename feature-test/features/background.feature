# language: en

Feature: Set the backround of the application
  As a system integrator
  I want to specify the background of the application
  In order to fit the application into the design

Scenario: Use a color for the background
  Given I have the following configuration file:
    """
    <cuteselect background-color="#041233" />
    """

  When I start the application

  Then I expect the background color to be "#041233"

Scenario: Use the default color for the background
  Given I have the following configuration file:
    """
    <cuteselect />
    """

  When I start the application

  Then I expect the background color to be "#000000"

