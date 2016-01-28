#
# (C) Copyright 2016
# Urs Fässler, bbv Software Services, http://bbv.ch
#
# SPDX-License-Identifier:	GPL-3.0+
#

# language: en

Feature: Show items to select from
  As a system integrator
  I want to add items that the application shows
  In order to see it on the application screen

Scenario: List items on the screen
  Given I have the following configuration file:
    """
    <cuteselect>
      <image value="value 1"      file="file1"  />
      <image value="second value" file="/file2" />
      <image value="3"            file="file3"  />
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
      <image value="value 1"      file="file 1" />
      <image value="second value" file="file 2" />
      <image value="3"            file="file 3" />
    </cuteselect>
    """
  And I start the application

  When I activate the item with the index 1 on the gui

  Then I expect the application to quit with "second value"
