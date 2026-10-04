
undefined4 __thiscall FUN_004351e4(uint *param_1,uint param_2)

{
  short sVar1;
  int iVar2;
  
  if ((*param_1 & param_2) == param_2) {
    iVar2 = FUN_00435221(param_2,0);
    sVar1 = *(short *)((int)param_1 + iVar2 * 2 + 8);
    if ((((sVar1 != 2) && (sVar1 != 0xc)) && (sVar1 != 0xd)) && (sVar1 != 0xe)) {
      return 1;
    }
  }
  return 0;
}

