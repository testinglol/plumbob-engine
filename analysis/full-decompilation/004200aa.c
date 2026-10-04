
undefined4 FUN_004200aa(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    uVar2 = param_1[1];
    pvVar3 = operator_new(param_2);
    *param_1 = (int)pvVar3;
    if (pvVar3 != (void *)0x0) {
      param_1[1] = param_2;
      if (param_2 < uVar2) {
        FUN_005a92b0(pvVar3,iVar1,param_2);
      }
      else {
        FUN_005a92b0(pvVar3,iVar1,uVar2);
        FUN_005a9250(*param_1 + uVar2,param_2 - uVar2,0);
      }
      FUN_006321f0(iVar1);
      return 0;
    }
    *param_1 = iVar1;
  }
  return 1;
}

