/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test_ctrl.h
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

#ifndef RTW_HEADER_test_ctrl_h_
#define RTW_HEADER_test_ctrl_h_
#ifndef test_ctrl_COMMON_INCLUDES_
#define test_ctrl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "DAHostLib_Network.h"
#endif                                 /* test_ctrl_COMMON_INCLUDES_ */

#include "test_ctrl_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T UDPReceive_o1;                /* '<Root>/UDP Receive' */
  real_T Gain;                         /* '<Root>/Gain' */
} B_test_ctrl_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UDPReceive_NetworkLib[137];   /* '<Root>/UDP Receive' */
  real_T UDPSend_NetworkLib[137];      /* '<Root>/UDP Send' */
  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      /* '<Root>/Scope2' */
} DW_test_ctrl_T;

/* Parameters (default storage) */
struct P_test_ctrl_T_ {
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<Root>/Gain'
                                        */
  int32_T UDPReceive_Port;             /* Computed Parameter: UDPReceive_Port
                                        * Referenced by: '<Root>/UDP Receive'
                                        */
  int32_T UDPSend_Port;                /* Computed Parameter: UDPSend_Port
                                        * Referenced by: '<Root>/UDP Send'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_test_ctrl_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_test_ctrl_T test_ctrl_P;

/* Block signals (default storage) */
extern B_test_ctrl_T test_ctrl_B;

/* Block states (default storage) */
extern DW_test_ctrl_T test_ctrl_DW;

/* Model entry point functions */
extern void test_ctrl_initialize(void);
extern void test_ctrl_step(void);
extern void test_ctrl_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test_ctrl_T *const test_ctrl_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'test_ctrl'
 */
#endif                                 /* RTW_HEADER_test_ctrl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
