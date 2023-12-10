/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test_ctrl.c
 *
 * Code generated for Simulink model 'test_ctrl'.
 *
 * Model version                  : 6.3
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Dec  5 20:11:33 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_ctrl.h"
#include "rtwtypes.h"
#include "test_ctrl_private.h"

/* Block signals (default storage) */
B_test_ctrl_T test_ctrl_B;

/* Block states (default storage) */
DW_test_ctrl_T test_ctrl_DW;

/* Real-time model */
static RT_MODEL_test_ctrl_T test_ctrl_M_;
RT_MODEL_test_ctrl_T *const test_ctrl_M = &test_ctrl_M_;

/* Model step function */
void test_ctrl_step(void)
{
  int32_T samplesRead;
  char_T *sErr;

  /* S-Function (sdspFromNetwork): '<Root>/UDP Receive' */
  sErr = GetErrorBuffer(&test_ctrl_DW.UDPReceive_NetworkLib[0U]);
  samplesRead = 1;
  LibOutputs_Network(&test_ctrl_DW.UDPReceive_NetworkLib[0U],
                     &test_ctrl_B.UDPReceive_o1, &samplesRead);
  if (*sErr != 0) {
    rtmSetErrorStatus(test_ctrl_M, sErr);
    rtmSetStopRequested(test_ctrl_M, 1);
  }

  /* End of S-Function (sdspFromNetwork): '<Root>/UDP Receive' */

  /* Gain: '<Root>/Gain' */
  test_ctrl_B.Gain = test_ctrl_P.Gain_Gain * test_ctrl_B.UDPReceive_o1;

  /* Update for S-Function (sdspToNetwork): '<Root>/UDP Send' */
  sErr = GetErrorBuffer(&test_ctrl_DW.UDPSend_NetworkLib[0U]);
  LibUpdate_Network(&test_ctrl_DW.UDPSend_NetworkLib[0U], &test_ctrl_B.Gain, 1);
  if (*sErr != 0) {
    rtmSetErrorStatus(test_ctrl_M, sErr);
    rtmSetStopRequested(test_ctrl_M, 1);
  }

  /* End of Update for S-Function (sdspToNetwork): '<Root>/UDP Send' */
  {                                    /* Sample time: [1.0s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  test_ctrl_M->Timing.taskTime0 =
    ((time_T)(++test_ctrl_M->Timing.clockTick0)) * test_ctrl_M->Timing.stepSize0;
}

/* Model initialize function */
void test_ctrl_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(test_ctrl_M, -1);
  test_ctrl_M->Timing.stepSize0 = 1.0;

  /* External mode info */
  test_ctrl_M->Sizes.checksums[0] = (2185210779U);
  test_ctrl_M->Sizes.checksums[1] = (1936684533U);
  test_ctrl_M->Sizes.checksums[2] = (3407183637U);
  test_ctrl_M->Sizes.checksums[3] = (2876583534U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    test_ctrl_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(test_ctrl_M->extModeInfo,
      &test_ctrl_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(test_ctrl_M->extModeInfo, test_ctrl_M->Sizes.checksums);
    rteiSetTPtr(test_ctrl_M->extModeInfo, rtmGetTPtr(test_ctrl_M));
  }

  {
    char_T *sErr;

    /* Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive' */
    sErr = GetErrorBuffer(&test_ctrl_DW.UDPReceive_NetworkLib[0U]);
    CreateUDPInterface(&test_ctrl_DW.UDPReceive_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&test_ctrl_DW.UDPReceive_NetworkLib[0U], 0, "0.0.0.0",
                        test_ctrl_P.UDPReceive_Port, "0.0.0.0", -1, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&test_ctrl_DW.UDPReceive_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&test_ctrl_DW.UDPReceive_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(test_ctrl_M, sErr);
        rtmSetStopRequested(test_ctrl_M, 1);
      }
    }

    /* End of Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive' */

    /* Start for S-Function (sdspToNetwork): '<Root>/UDP Send' */
    sErr = GetErrorBuffer(&test_ctrl_DW.UDPSend_NetworkLib[0U]);
    CreateUDPInterface(&test_ctrl_DW.UDPSend_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&test_ctrl_DW.UDPSend_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "192.168.137.1", test_ctrl_P.UDPSend_Port, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&test_ctrl_DW.UDPSend_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&test_ctrl_DW.UDPSend_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(test_ctrl_M, sErr);
        rtmSetStopRequested(test_ctrl_M, 1);
      }
    }

    /* End of Start for S-Function (sdspToNetwork): '<Root>/UDP Send' */
  }
}

/* Model terminate function */
void test_ctrl_terminate(void)
{
  char_T *sErr;

  /* Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive' */
  sErr = GetErrorBuffer(&test_ctrl_DW.UDPReceive_NetworkLib[0U]);
  LibTerminate(&test_ctrl_DW.UDPReceive_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(test_ctrl_M, sErr);
    rtmSetStopRequested(test_ctrl_M, 1);
  }

  LibDestroy(&test_ctrl_DW.UDPReceive_NetworkLib[0U], 0);
  DestroyUDPInterface(&test_ctrl_DW.UDPReceive_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive' */

  /* Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send' */
  sErr = GetErrorBuffer(&test_ctrl_DW.UDPSend_NetworkLib[0U]);
  LibTerminate(&test_ctrl_DW.UDPSend_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(test_ctrl_M, sErr);
    rtmSetStopRequested(test_ctrl_M, 1);
  }

  LibDestroy(&test_ctrl_DW.UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&test_ctrl_DW.UDPSend_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
