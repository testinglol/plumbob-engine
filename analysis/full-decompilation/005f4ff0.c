
undefined4 __fastcall FUN_005f4ff0(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 0x174))(0,0);
  }
  FUN_005dbf4d();
  param_1[0x39] = 0;
  param_1[0x38] = 0;
  FUN_0052ea87(param_1[0x35],param_1[0x36]);
  return 1;
}

