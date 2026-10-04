
void __thiscall FUN_0059af08(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *param_1;
  if ((uint)((param_1[2] - iVar1) / 0xc) < param_2) {
    iVar2 = param_1[1];
    iVar4 = FUN_0059b234(param_2,iVar1,iVar2);
    iVar3 = param_1[1];
    for (iVar5 = *param_1; iVar5 != iVar3; iVar5 = iVar5 + 0xc) {
      FUN_005b8770();
    }
    if ((param_1[2] - *param_1) / 0xc != 0) {
      FUN_0041d9a9(*param_1);
    }
    *param_1 = iVar4;
    param_1[1] = iVar4 + ((iVar2 - iVar1) / 0xc) * 0xc;
    param_1[2] = iVar4 + param_2 * 0xc;
  }
  return;
}

