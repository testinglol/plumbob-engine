
int * __thiscall FUN_004b5576(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_2 != param_1) {
    iVar2 = *param_2;
    iVar3 = *param_1;
    iVar1 = param_2[1];
    uVar5 = iVar1 - iVar2 >> 2;
    if ((uint)(param_1[2] - iVar3 >> 2) < uVar5) {
      iVar2 = FUN_004b5639(uVar5,iVar2,iVar1);
      iVar3 = param_1[2] - *param_1 >> 2;
      if (iVar3 != 0) {
        FUN_0040189d(*param_1,iVar3 << 2);
      }
      *param_1 = iVar2;
      param_1[2] = iVar2 + uVar5 * 4;
    }
    else {
      uVar4 = param_1[1] - iVar3 >> 2;
      if (uVar4 < uVar5) {
        FUN_004b56ae(iVar2,iVar2 + uVar4 * 4,iVar3);
        FUN_0047d986(*param_2 + (param_1[1] - *param_1 >> 2) * 4,param_2[1],param_1[1],iVar1);
      }
      else {
        FUN_004b56ae(iVar2,iVar1,iVar3);
      }
    }
    param_1[1] = *param_1 + uVar5 * 4;
  }
  return param_1;
}

