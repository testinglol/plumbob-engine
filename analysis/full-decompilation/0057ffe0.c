
undefined4 __fastcall FUN_0057ffe0(int *param_1)

{
  if (param_1[0x35] != 0) {
    param_1[0x35] = 1;
    (**(code **)(*param_1 + 100))();
  }
  if ((int *)param_1[0x39] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x39] + 4))();
    param_1[0x39] = 0;
  }
  if ((int *)param_1[0x38] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x38] + 4))();
    param_1[0x38] = 0;
  }
  return 1;
}

