#pragma once
#include <eigen3/Eigen/Core>


namespace gener_alldata_node {

/*!
 * Class containing the algorithmic part of the package.
 */
class Param
{
 public:
  /*!
   * Constructor.
   */
  Param();

  /*!
   * Destructor.
   */
  virtual ~Param();

  /*!
   * Add new measurement data.
   * @param data the new data.
   */
  void addData(const double data);

  /*!
   * Get the computed average of the data.
   * @return the average of the data.
   */
  double getAverage() const;

 private:

  //! Internal variable to hold the current average.
  double average_;

  //! Number of measurements taken.
  unsigned int nMeasurements_;

    // time
    int imu_frequency = 200;
    int cam_frequency = 30;
    double imu_timestep = 1./imu_frequency;
    double cam_timestep = 1./cam_frequency;
    double t_start = 0.;
    double t_end = 20;  //  20 s

    // noise
    double gyro_bias_sigma = 1.0e-5;
    double acc_bias_sigma = 0.0001;

    double gyro_noise_sigma = 0.015;    // rad/s * 1/sqrt(hz)
    double acc_noise_sigma = 0.019;      //　m/(s^2) * 1/sqrt(hz)

    double pixel_noise = 1;              // 1 pixel noise

    // cam f
    double fx = 460;
    double fy = 460;
    double cx = 255;
    double cy = 255;
    double image_w = 640;
    double image_h = 640;


    // 外参数
    Eigen::Matrix3d R_bc;   // cam to body
    Eigen::Vector3d t_bc;     // cam to body

};

} /* namespace */
