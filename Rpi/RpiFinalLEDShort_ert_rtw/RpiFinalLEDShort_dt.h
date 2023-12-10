/*
 * RpiFinalLEDShort_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(codertarget_raspi_internal_LE_T),
  sizeof(fixed_system_ModByConstant_Rp_T),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "codertarget_raspi_internal_LE_T",
  "fixed_system_ModByConstant_Rp_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&RpiFinalLEDShort_B.DataTypeConversion2), 0, 0, 1 },

  { (char_T *)(&RpiFinalLEDShort_B.NOT), 8, 0, 2 }
  ,

  { (char_T *)(&RpiFinalLEDShort_DW.obj), 15, 0, 1 },

  { (char_T *)(&RpiFinalLEDShort_DW.Delay1_DSTATE), 0, 0, 138 },

  { (char_T *)(&RpiFinalLEDShort_DW.Scope_PWORK.LoggedData[0]), 11, 0, 2 },

  { (char_T *)(&RpiFinalLEDShort_DW.clockTickCounter), 6, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* [EOF] RpiFinalLEDShort_dt.h */
