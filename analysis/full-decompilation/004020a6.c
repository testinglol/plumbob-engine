
int FUN_004020a6(undefined4 param_1,short param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040204f(param_1);
  if (((iVar1 == 0) || (param_2 < 0)) || (*(short *)(iVar1 + 2) <= param_2)) {
    iVar1 = 0;
  }
  else {
    iVar1 = iVar1 + (param_2 + 1) * 0xc;
  }
  return iVar1;
}

