
void __thiscall FUN_004b3f82(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *param_1;
  if ((uint)(param_1[2] - iVar1 >> 4) < param_2) {
    iVar2 = param_1[1];
    iVar3 = FUN_004b4095(param_2,iVar1,iVar2);
    iVar4 = param_1[2] - *param_1 >> 4;
    if (iVar4 != 0) {
      FUN_0040189d(*param_1,iVar4 << 4);
    }
    param_1[1] = (iVar2 - iVar1 >> 4) * 0x10 + iVar3;
    *param_1 = iVar3;
    param_1[2] = param_2 * 0x10 + iVar3;
  }
  return;
}

