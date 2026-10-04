
uint __thiscall FUN_005dd854(int *param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int unaff_retaddr;
  
  uVar1 = (**(code **)(*param_1 + 0x8c))(8);
  if (((char)uVar1 == '\0') && ((int *)param_1[0x10] != (int *)0x0)) {
    uVar1 = (**(code **)(*(int *)param_1[0x10] + 0xfc))
                      (unaff_retaddr + param_1[0x1f],param_2 + param_1[0x20],param_3);
  }
  else {
    uVar1 = uVar1 & 0xffffff00;
  }
  return uVar1;
}

