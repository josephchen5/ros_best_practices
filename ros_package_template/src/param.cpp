#include "ros_package_template/param.hpp"

namespace gener_alldata_node {

Param::Param()
    : average_(0.0),
      nMeasurements_(0)
{
}

Param::~Param()
{
}

void Param::addData(const double data)
{
  average_ = (nMeasurements_ * average_ + data) / (nMeasurements_ + 1);
  nMeasurements_++;
}

double Param::getAverage() const
{
  return average_;
}

} /* namespace */
