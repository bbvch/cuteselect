#include "ApplicationImplementation.h"

ApplicationImplementation::ApplicationImplementation(const Configuration &configuration) :
  backgroundColor{configuration.backgroundColor()}
{
}
