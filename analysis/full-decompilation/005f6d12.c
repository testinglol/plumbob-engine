
undefined4 __thiscall FUN_005f6d12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int *piVar2;
  int *local_8;
  
  local_8 = param_1;
  piVar2 = (int *)FUN_00492d2c();
  if (piVar2 == param_1) {
    FUN_005d9912(param_1);
    if (param_1[0x54] == 5) {
      cVar1 = (**(code **)(*param_1 + 0x1c0))(&local_8,param_2,param_3);
      if (cVar1 != '\0') {
        (**(code **)(*param_1 + 0x1a8))(local_8);
      }
    }
    param_1[0x54] = 0;
    (**(code **)(*param_1 + 0x168))();
  }
  return 1;
}

