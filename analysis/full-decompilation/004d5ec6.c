
void __thiscall FUN_004d5ec6(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *param_1;
  if ((uint)((param_1[2] - iVar1) / 0xc) < param_2) {
    iVar2 = param_1[1];
    iVar3 = FUN_004d5fd8(param_2,iVar1,iVar2);
    iVar4 = param_1[1];
    for (iVar5 = *param_1; iVar5 != iVar4; iVar5 = iVar5 + 0xc) {
      FUN_005b8770();
    }
    iVar4 = (param_1[2] - *param_1) / 0xc;
    if (iVar4 != 0) {
      FUN_0040189d(*param_1,iVar4 * 0xc);
    }
    *param_1 = iVar3;
    param_1[1] = iVar3 + ((iVar2 - iVar1) / 0xc) * 0xc;
    param_1[2] = iVar3 + param_2 * 0xc;
  }
  return;
}

