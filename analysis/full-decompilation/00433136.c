
undefined4 __thiscall FUN_00433136(int param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((*param_2 < '\x01') || (iVar1 = *(int *)(param_1 + 0x10) + -1, iVar1 <= *param_2)) ||
      (param_2[1] < '\x01')) || (iVar1 <= param_2[1])) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

