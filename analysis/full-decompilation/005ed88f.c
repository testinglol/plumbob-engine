
undefined4 * __fastcall FUN_005ed88f(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[3] = 100;
  param_1[4] = 1000;
  *(undefined1 *)(param_1 + 5) = 0;
  *(undefined1 *)((int)param_1 + 0x15) = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  *param_1 = &PTR_LAB_00675148;
  InterlockedIncrement(param_1 + 7);
  return param_1;
}

