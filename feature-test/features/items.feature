# language: en

Feature: Show items to select from
  As a system integrator
  I want to add items that the application shows
  In order to see it on the application screen

Scenario: List items on the screen
  Given I have the following configuration file:
    """
    <cuteselect>
      <image file="file1" />
      <image file="file2" />
      <image file="file3" />
    </cuteselect>
    """

  When I start the application

  Then I expect to see the following images in this order on the screen:
    | filename |
    | file1    |
    | file2    |
    | file3    |

