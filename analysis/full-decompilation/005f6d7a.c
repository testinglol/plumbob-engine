
undefined4 __thiscall FUN_005f6d7a(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int *piVar2;
  int *local_c;
  int *local_8;
  
  local_c = param_1;
  local_8 = param_1;
  piVar2 = (int *)FUN_00492d2c();
  if (piVar2 == param_1) {
    if (param_1[0x54] == 5) {
      cVar1 = (**(code **)(*param_1 + 0x1c0))(&local_8);
      if (cVar1 != '\0') {
        (**(code **)(*param_1 + 0x1a8))(local_8);
      }
    }
    else {
      cVar1 = (**(code **)(*param_1 + 0x1d8))(&local_c,param_2,param_3);
      if (cVar1 == '\0') {
        *(undefined1 *)(param_1 + 0x55) = 0;
      }
      else {
        *(bool *)(param_1 + 0x55) = local_c == (int *)param_1[0x54];
      }
    }
  }
  return 1;
}

