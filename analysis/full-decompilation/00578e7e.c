
undefined4 __fastcall FUN_00578e7e(int *param_1)

{
  if ((char)param_1[1] != '\0') {
    if ((char)param_1[0xf] == '\0') {
      return 0;
    }
    (**(code **)(*param_1 + 0xa0))();
    (**(code **)(*param_1 + 0xa8))();
  }
  return 1;
}

