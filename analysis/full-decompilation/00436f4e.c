
undefined1 __thiscall FUN_00436f4e(int *param_1,int param_2,int param_3)

{
  char cVar1;
  undefined1 uVar2;
  
  if ((((param_3 < 0) || (param_2 < 0)) || (param_1[0x22] - param_1[0x20] <= param_3)) ||
     (param_1[0x21] - param_1[0x1f] <= param_2)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    cVar1 = (**(code **)(*param_1 + 0x8c))(0x200);
    if ((cVar1 != '\0') && (param_1[0x16] != 0)) {
      uVar2 = FUN_005dd6a6(param_1[0x16],param_2,param_3);
    }
  }
  return uVar2;
}

