
int * __thiscall FUN_0048e788(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if (param_2 != param_1) {
    iVar2 = param_2[1];
    iVar5 = *param_2;
    uVar3 = (iVar2 - iVar5) / 0x28;
    iVar4 = *param_1;
    if ((uint)((param_1[2] - iVar4) / 0x28) < uVar3) {
      iVar4 = FUN_0048e8eb(uVar3,iVar5,iVar2);
      iVar5 = param_1[1];
      iVar2 = *param_1;
      for (param_2 = (int *)iVar2; param_2 != (int *)iVar5; param_2 = (int *)((int)param_2 + 0x28))
      {
        FUN_0048ddf7();
      }
      iVar5 = (param_1[2] - iVar2) / 0x28;
      if (iVar5 != 0) {
        FUN_0040189d(iVar2,iVar5 * 0x28);
      }
      *param_1 = iVar4;
      param_1[2] = iVar4 + uVar3 * 0x28;
    }
    else {
      uVar6 = (param_1[1] - iVar4) / 0x28;
      if (uVar6 < uVar3) {
        iVar1 = iVar5 + uVar6 * 0x28;
        FUN_0048e62b(iVar5,iVar1,iVar4);
        FUN_0048e9da(iVar1,iVar2,param_1[1],iVar2);
      }
      else {
        iVar5 = FUN_0048e62b(iVar5,iVar2,iVar4);
        iVar2 = param_1[1];
        for (; iVar5 != iVar2; iVar5 = iVar5 + 0x28) {
          FUN_0048ddf7();
        }
      }
    }
    param_1[1] = *param_1 + uVar3 * 0x28;
  }
  return param_1;
}

