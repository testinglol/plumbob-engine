
undefined4 __thiscall FUN_00603147(int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (*(int *)(iVar2 + 4) != 0) {
    iVar1 = *(int *)(iVar2 + 4);
    do {
      iVar2 = iVar1;
      if (*param_3 < *(int *)(iVar2 + 0x10)) {
        iVar1 = *(int *)(iVar2 + 8);
      }
      else {
        iVar1 = *(int *)(iVar2 + 0xc);
      }
    } while (iVar1 != 0);
  }
  FUN_006031c1(param_2,0,iVar2,param_3);
  return param_2;
}

