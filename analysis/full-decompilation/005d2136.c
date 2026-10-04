
int * __thiscall FUN_005d2136(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_2 != param_1) {
    iVar2 = param_2[1];
    iVar3 = *param_2;
    iVar1 = *param_1;
    uVar5 = iVar2 - iVar3 >> 1;
    if ((uint)(param_1[2] - iVar1 >> 1) < uVar5) {
      iVar2 = FUN_005d21f6(uVar5,iVar3,iVar2);
      iVar3 = param_1[2] - *param_1 >> 1;
      if (iVar3 != 0) {
        FUN_0040189d(*param_1,iVar3 * 2);
      }
      *param_1 = iVar2;
      param_1[2] = iVar2 + uVar5 * 2;
    }
    else {
      uVar4 = param_1[1] - iVar1 >> 1;
      if (uVar4 < uVar5) {
        FUN_00635190(iVar1,iVar3,((int)(uVar4 * 2) >> 1) << 1);
        iVar2 = *param_2 + (param_1[1] - *param_1 >> 1) * 2;
        FUN_00635190(param_1[1],iVar2,(param_2[1] - iVar2 >> 1) << 1);
      }
      else {
        FUN_00635190(iVar1,iVar3,(iVar2 - iVar3 >> 1) << 1);
      }
    }
    param_1[1] = *param_1 + uVar5 * 2;
  }
  return param_1;
}

