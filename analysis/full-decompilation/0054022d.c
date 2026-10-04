
int * __thiscall FUN_0054022d(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (param_2 != param_1) {
    iVar2 = param_2[1];
    iVar3 = *param_2;
    uVar1 = (iVar2 - iVar3) / 6;
    if ((uint)((param_1[2] - *param_1) / 6) < uVar1) {
      iVar2 = FUN_0053ffda(uVar1,iVar3,iVar2);
      iVar3 = (param_1[2] - *param_1) / 6;
      if (iVar3 != 0) {
        FUN_0040189d(*param_1,iVar3 * 6);
      }
      *param_1 = iVar2;
      param_1[2] = iVar2 + uVar1 * 6;
    }
    else {
      uVar4 = (param_1[1] - *param_1) / 6;
      if (uVar4 < uVar1) {
        FUN_0054036c(iVar3,iVar3 + uVar4 * 6,*param_1);
        FUN_00540424(*param_2 + ((param_1[1] - *param_1) / 6) * 6,param_2[1],param_1[1],uVar1);
      }
      else {
        FUN_0054036c(iVar3,iVar2,*param_1);
      }
    }
    param_1[1] = *param_1 + uVar1 * 6;
  }
  return param_1;
}

