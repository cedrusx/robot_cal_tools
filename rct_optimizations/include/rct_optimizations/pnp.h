#ifndef RCT_PNP_H
#define RCT_PNP_H

#include <rct_optimizations/types.h>

namespace rct_optimizations
{

struct PnPProblem
{
  rct_optimizations::CameraIntrinsics intr;
  Correspondence2D3D::Set correspondences;

  Eigen::Isometry3d camera_to_target_guess;
};

struct PnPProblem3D
{
  Correspondence3D3D::Set correspondences;

  Eigen::Isometry3d camera_to_target_guess;
};

struct PnPResult
{
  bool converged;
  double initial_cost_per_obs;
  double final_cost_per_obs;

  Eigen::Isometry3d camera_to_target;
  Eigen::MatrixXd camera_to_target_covariance;
};

PnPResult optimize(const PnPProblem& params);
PnPResult optimize(const PnPProblem3D& params);

}

#endif // RCT_PNP_H
