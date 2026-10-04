
int * __thiscall FUN_00468cf3(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (param_2 != param_1) {
    iVar2 = param_2[1];
    iVar3 = *param_2;
    uVar1 = (iVar2 - iVar3) / 3;
    if ((uint)((param_1[2] - *param_1) / 3) < uVar1) {
      iVar2 = FUN_00469354(uVar1,iVar3,iVar2);
      iVar3 = (param_1[2] - *param_1) / 3;
      if (iVar3 != 0) {
        FUN_0040189d(*param_1,iVar3 * 3);
      }
      *param_1 = iVar2;
      param_1[2] = uVar1 + iVar2 + uVar1 * 2;
    }
    else {
      uVar4 = (param_1[1] - *param_1) / 3;
      if (uVar4 < uVar1) {
        FUN_0047d87e(iVar3,iVar3 + uVar4 * 3,*param_1);
        FUN_0047d95b(((param_1[1] - *param_1) / 3) * 3 + *param_2,param_2[1],param_1[1],uVar1);
      }
      else {
        FUN_0047d87e(iVar3,iVar2,*param_1);
      }
    }
    param_1[1] = uVar1 * 3 + *param_1;
  }
  return param_1;
}

