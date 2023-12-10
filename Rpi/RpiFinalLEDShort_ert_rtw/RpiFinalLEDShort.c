/*
 * RpiFinalLEDShort.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "RpiFinalLEDShort".
 *
 * Model version              : 7.24
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Sat Dec  9 21:56:21 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RpiFinalLEDShort.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>
#include "RpiFinalLEDShort_private.h"
#include "RpiFinalLEDShort_dt.h"

/* Block signals (default storage) */
B_RpiFinalLEDShort_T RpiFinalLEDShort_B;

/* Block states (default storage) */
DW_RpiFinalLEDShort_T RpiFinalLEDShort_DW;

/* Real-time model */
static RT_MODEL_RpiFinalLEDShort_T RpiFinalLEDShort_M_;
RT_MODEL_RpiFinalLEDShort_T *const RpiFinalLEDShort_M = &RpiFinalLEDShort_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void RpiFinalLEDShort_step(void)
{
  real_T rtb_PulseGenerator;
  real_T yTemp;
  int32_T i;
  char_T d[5];
  char_T *sErr;
  uint8_T tmp;
  static const char_T tmp_0[69] = { 'I', 'n', 'v', 'a', 'l', 'i', 'd', ' ', 'L',
    'E', 'D', ' ', 'v', 'a', 'l', 'u', 'e', '.', ' ', 'L', 'E', 'D', ' ', 'v',
    'a', 'l', 'u', 'e', ' ', 'm', 'u', 's', 't', ' ', 'b', 'e', ' ', 'a', ' ',
    'l', 'o', 'g', 'i', 'c', 'a', 'l', ' ', 'v', 'a', 'l', 'u', 'e', ' ', '(',
    't', 'r', 'u', 'e', ' ', 'o', 'r', ' ', 'f', 'a', 'l', 's', 'e', ')', '.' };

  static const char_T tmp_1[5] = "none";

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = ((RpiFinalLEDShort_DW.clockTickCounter < 5) &&
                        (RpiFinalLEDShort_DW.clockTickCounter >= 0));
  if (RpiFinalLEDShort_DW.clockTickCounter >= 9) {
    RpiFinalLEDShort_DW.clockTickCounter = 0;
  } else {
    RpiFinalLEDShort_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Modulo by Constant1' */
  if (rtb_PulseGenerator == 0.0) {
    rtb_PulseGenerator = 0.0;
  } else {
    rtb_PulseGenerator = 1.0;
  }

  /* Logic: '<Root>/NOT' incorporates:
   *  MATLABSystem: '<Root>/Modulo by Constant1'
   */
  RpiFinalLEDShort_B.NOT = !(rtb_PulseGenerator != 0.0);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  yTemp = ((RpiFinalLEDShort_DW.clockTickCounter_j1xnvi444m < 1) &&
           (RpiFinalLEDShort_DW.clockTickCounter_j1xnvi444m >= 0));
  if (RpiFinalLEDShort_DW.clockTickCounter_j1xnvi444m >= 0) {
    RpiFinalLEDShort_DW.clockTickCounter_j1xnvi444m = 0;
  } else {
    RpiFinalLEDShort_DW.clockTickCounter_j1xnvi444m++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator1' */

  /* Sum: '<Root>/Sum1' incorporates:
   *  Delay: '<Root>/Delay1'
   */
  rtb_PulseGenerator = yTemp + RpiFinalLEDShort_DW.Delay1_DSTATE;

  /* MATLABSystem: '<Root>/Modulo by Constant' */
  if (rtIsNaN(rtb_PulseGenerator) || rtIsInf(rtb_PulseGenerator)) {
    yTemp = (rtNaN);
  } else if (rtb_PulseGenerator == 0.0) {
    yTemp = 0.0;
  } else {
    yTemp = fmod(rtb_PulseGenerator, 24.0);
    if (yTemp == 0.0) {
      yTemp = 0.0;
    } else if (rtb_PulseGenerator < 0.0) {
      yTemp += 24.0;
    }
  }

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLABSystem: '<Root>/Modulo by Constant'
   */
  RpiFinalLEDShort_B.Compare = (yTemp >= 23.0);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Logic: '<Root>/OR'
   */
  RpiFinalLEDShort_B.DataTypeConversion2 = (RpiFinalLEDShort_B.NOT ||
    RpiFinalLEDShort_B.Compare);

  /* MATLABSystem: '<Root>/LED' */
  rtb_PulseGenerator = RpiFinalLEDShort_B.DataTypeConversion2;
  if ((rtb_PulseGenerator == 0.0) || (rtb_PulseGenerator == 1.0)) {
  } else {
    memcpy(&RpiFinalLEDShort_B.c[0], &tmp_0[0], 69U * sizeof(char_T));
    perror(&RpiFinalLEDShort_B.c[0]);
  }

  for (i = 0; i < 5; i++) {
    d[i] = tmp_1[i];
  }

  EXT_LED_setTrigger(0U, &d[0]);
  rtb_PulseGenerator = rt_roundd_snf(rtb_PulseGenerator);
  if (rtb_PulseGenerator < 256.0) {
    if (rtb_PulseGenerator >= 0.0) {
      tmp = (uint8_T)rtb_PulseGenerator;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  EXT_LED_write(0U, tmp);

  /* End of MATLABSystem: '<Root>/LED' */
  /* Update for Delay: '<Root>/Delay1' incorporates:
   *  MATLABSystem: '<Root>/Modulo by Constant'
   */
  RpiFinalLEDShort_DW.Delay1_DSTATE = yTemp;

  /* Update for S-Function (sdspToNetwork): '<Root>/UDP Send' */
  sErr = GetErrorBuffer(&RpiFinalLEDShort_DW.UDPSend_NetworkLib[0U]);
  LibUpdate_Network(&RpiFinalLEDShort_DW.UDPSend_NetworkLib[0U],
                    &RpiFinalLEDShort_B.DataTypeConversion2, 1);
  if (*sErr != 0) {
    rtmSetErrorStatus(RpiFinalLEDShort_M, sErr);
    rtmSetStopRequested(RpiFinalLEDShort_M, 1);
  }

  /* End of Update for S-Function (sdspToNetwork): '<Root>/UDP Send' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [1.0s, 0.0s] */
    rtExtModeUpload(0, (real_T)RpiFinalLEDShort_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [1.0s, 0.0s] */
    if ((rtmGetTFinal(RpiFinalLEDShort_M)!=-1) &&
        !((rtmGetTFinal(RpiFinalLEDShort_M)-RpiFinalLEDShort_M->Timing.taskTime0)
          > RpiFinalLEDShort_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(RpiFinalLEDShort_M, "Simulation finished");
    }

    if (rtmGetStopRequested(RpiFinalLEDShort_M)) {
      rtmSetErrorStatus(RpiFinalLEDShort_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  RpiFinalLEDShort_M->Timing.taskTime0 =
    ((time_T)(++RpiFinalLEDShort_M->Timing.clockTick0)) *
    RpiFinalLEDShort_M->Timing.stepSize0;
}

/* Model initialize function */
void RpiFinalLEDShort_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)RpiFinalLEDShort_M, 0,
                sizeof(RT_MODEL_RpiFinalLEDShort_T));
  rtmSetTFinal(RpiFinalLEDShort_M, 48.0);
  RpiFinalLEDShort_M->Timing.stepSize0 = 1.0;

  /* External mode info */
  RpiFinalLEDShort_M->Sizes.checksums[0] = (1798180693U);
  RpiFinalLEDShort_M->Sizes.checksums[1] = (3921660464U);
  RpiFinalLEDShort_M->Sizes.checksums[2] = (45962326U);
  RpiFinalLEDShort_M->Sizes.checksums[3] = (2102995143U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    RpiFinalLEDShort_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(RpiFinalLEDShort_M->extModeInfo,
      &RpiFinalLEDShort_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(RpiFinalLEDShort_M->extModeInfo,
                        RpiFinalLEDShort_M->Sizes.checksums);
    rteiSetTPtr(RpiFinalLEDShort_M->extModeInfo, rtmGetTPtr(RpiFinalLEDShort_M));
  }

  /* block I/O */
  (void) memset(((void *) &RpiFinalLEDShort_B), 0,
                sizeof(B_RpiFinalLEDShort_T));

  /* states (dwork) */
  (void) memset((void *)&RpiFinalLEDShort_DW, 0,
                sizeof(DW_RpiFinalLEDShort_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    RpiFinalLEDShort_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  {
    int32_T i;
    char_T b[5];
    char_T *sErr;
    static const char_T tmp[5] = "none";

    /* Start for MATLABSystem: '<Root>/LED' */
    RpiFinalLEDShort_DW.obj.matlabCodegenIsDeleted = false;
    RpiFinalLEDShort_DW.obj.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      b[i] = tmp[i];
    }

    EXT_LED_setTrigger(0U, &b[0]);
    RpiFinalLEDShort_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/LED' */

    /* Start for S-Function (sdspToNetwork): '<Root>/UDP Send' */
    sErr = GetErrorBuffer(&RpiFinalLEDShort_DW.UDPSend_NetworkLib[0U]);
    CreateUDPInterface(&RpiFinalLEDShort_DW.UDPSend_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&RpiFinalLEDShort_DW.UDPSend_NetworkLib[0U], 1,
                        "0.0.0.0", -1, "192.168.137.1", 26000, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&RpiFinalLEDShort_DW.UDPSend_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&RpiFinalLEDShort_DW.UDPSend_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(RpiFinalLEDShort_M, sErr);
        rtmSetStopRequested(RpiFinalLEDShort_M, 1);
      }
    }

    /* End of Start for S-Function (sdspToNetwork): '<Root>/UDP Send' */

    /* InitializeConditions for DiscretePulseGenerator: '<Root>/Pulse Generator' */
    RpiFinalLEDShort_DW.clockTickCounter = 0;

    /* InitializeConditions for DiscretePulseGenerator: '<Root>/Pulse Generator1' */
    RpiFinalLEDShort_DW.clockTickCounter_j1xnvi444m = 0;
  }
}

/* Model terminate function */
void RpiFinalLEDShort_terminate(void)
{
  char_T *sErr;

  /* Terminate for MATLABSystem: '<Root>/LED' */
  if (!RpiFinalLEDShort_DW.obj.matlabCodegenIsDeleted) {
    RpiFinalLEDShort_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED' */

  /* Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send' */
  sErr = GetErrorBuffer(&RpiFinalLEDShort_DW.UDPSend_NetworkLib[0U]);
  LibTerminate(&RpiFinalLEDShort_DW.UDPSend_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(RpiFinalLEDShort_M, sErr);
    rtmSetStopRequested(RpiFinalLEDShort_M, 1);
  }

  LibDestroy(&RpiFinalLEDShort_DW.UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&RpiFinalLEDShort_DW.UDPSend_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send' */
}
