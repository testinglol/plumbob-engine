
undefined4 __thiscall FUN_005f60e2(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1[0x35] == 1) {
    (**(code **)(*param_1 + 0x1cc))();
  }
  else {
    (**(code **)(*param_1 + 0x1d0))();
  }
  iVar2 = __ftol();
  *param_2 = iVar2;
  iVar1 = param_1[0x36];
  *param_2 = iVar2 + iVar1;
  return CONCAT31((int3)((uint)(iVar2 + iVar1) >> 8),1);
}

