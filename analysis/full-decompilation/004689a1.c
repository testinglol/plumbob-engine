
float10 __fastcall FUN_004689a1(int param_1)

{
  if ((*(char *)(param_1 + 0x75) == '\0') &&
     ((((*(char *)(param_1 + 0x73) == '\0' || (*(int *)(param_1 + 0x280) != 0)) ||
       (*(int *)(param_1 + 0x284) < 1)) || (DAT_00667638 <= *(float *)(param_1 + 0x6c))))) {
    return (float10)*(float *)(param_1 + 0x6c);
  }
  return (float10)DAT_00667638;
}

