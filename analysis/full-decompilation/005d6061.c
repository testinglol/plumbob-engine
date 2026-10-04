
int * __thiscall FUN_005d6061(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (param_2 != param_1) {
    iVar3 = param_2[1];
    iVar5 = *param_2;
    uVar1 = (iVar3 - iVar5) / 0xc;
    if ((uint)((param_1[2] - *param_1) / 0xc) < uVar1) {
      iVar2 = FUN_005d619e(uVar1,iVar5,iVar3);
      iVar3 = param_1[1];
      for (iVar5 = *param_1; iVar5 != iVar3; iVar5 = iVar5 + 0xc) {
        FUN_005b8770();
      }
      iVar3 = (param_1[2] - *param_1) / 0xc;
      if (iVar3 != 0) {
        FUN_0040189d(*param_1,iVar3 * 0xc);
      }
      *param_1 = iVar2;
      param_1[2] = iVar2 + uVar1 * 0xc;
    }
    else {
      uVar4 = (param_1[1] - *param_1) / 0xc;
      if (uVar4 < uVar1) {
        FUN_005d6219(iVar5,iVar5 + uVar4 * 0xc,*param_1);
        FUN_005d624f(*param_2 + ((param_1[1] - *param_1) / 0xc) * 0xc,param_2[1],param_1[1],uVar1);
      }
      else {
        iVar5 = FUN_005d6219(iVar5,iVar3,*param_1);
        iVar3 = param_1[1];
        for (; iVar5 != iVar3; iVar5 = iVar5 + 0xc) {
          FUN_005b8770();
        }
      }
    }
    param_1[1] = *param_1 + uVar1 * 0xc;
  }
  return param_1;
}

