/*
 * Medical Image Registration ToolKit (MIRTK)
 *
 * Copyright 2013-2015 Imperial College London
 * Copyright 2013-2015 Andreas Schuh
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <mirtkTransformationConfig.h>
#include <mirtkObjectFactory.h>

#ifndef MIRTK_AUTO_REGISTER
  #include <mirtkSmoothnessConstraint.h>
  #include <mirtkLogJacobianConstraint.h>
  #include <mirtkMinJacobianConstraint.h>
  #include <mirtkTopologyPreservationConstraint.h>
  #include <mirtkVolumePreservationConstraint.h>
  #include <mirtkSparsityConstraint.h>
#endif


namespace mirtk {


// -----------------------------------------------------------------------------
static void RegisterTransformationConstraints()
{
  #ifndef MIRTK_AUTO_REGISTER
    mirtkRegisterEnergyTermMacro(SmoothnessConstraint);
    mirtkRegisterEnergyTermMacro(LogJacobianConstraint);
    mirtkRegisterEnergyTermMacro(MinJacobianConstraint);
    mirtkRegisterEnergyTermMacro(TopologyPreservationConstraint);
    mirtkRegisterEnergyTermMacro(VolumePreservationConstraint);
    mirtkRegisterEnergyTermMacro(SparsityConstraint);
  #endif
}

// -----------------------------------------------------------------------------
void InitializeTransformationLibrary()
{
  static bool initialized = false;
  if (!initialized) {
    RegisterTransformationConstraints();
    initialized = true;
  }
}


} // namespace mirtk