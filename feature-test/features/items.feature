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
      <image file="/file2" />
      <image file="file3" />
    </cuteselect>
    """
  And the configuration file is stored at "/path"

  When I start the application

  Then I expect to see the following images in this order on the screen:
    | filename    |
    | /path/file1 |
    | /file2      |
    | /path/file3 |

Scenario: Select an item on the screen
  Given I have the following configuration file:
    """
    <cuteselect>
      <image file="file1" />
      <image file="file2" />
      <image file="file3" />
    </cuteselect>
    """
  And I start the application

  When I activate the item "file2" on the gui

  Then I expect the application to quit with "file2" followed by a newline

Scenario: The files are relative to the configuration file
  Given I have the following configuration file:
    """
    <cuteselect>
      <image file="file" />
    </cuteselect>
    """
  And the configuration file is stored at "/path"

  When I start the application

  Then I expect to see the following images in this order on the screen:
    | filename   |
    | /path/file |
