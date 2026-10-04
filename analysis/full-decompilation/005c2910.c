
int * __thiscall FUN_005c2910(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if (param_2 != param_1) {
    iVar5 = *param_2;
    iVar1 = *param_1;
    iVar2 = param_2[1];
    uVar4 = iVar2 - iVar5 >> 2;
    if ((uint)(param_1[2] - iVar1 >> 2) < uVar4) {
      iVar2 = FUN_005c2a17(uVar4,iVar5,iVar2);
      iVar1 = param_1[1];
      for (iVar5 = *param_1; iVar5 != iVar1; iVar5 = iVar5 + 4) {
        FUN_0042004f();
      }
      iVar5 = param_1[2] - *param_1 >> 2;
      if (iVar5 != 0) {
        FUN_0040189d(*param_1,iVar5 << 2);
      }
      *param_1 = iVar2;
      param_1[2] = iVar2 + uVar4 * 4;
    }
    else {
      uVar3 = param_1[1] - iVar1 >> 2;
      if (uVar3 < uVar4) {
        FUN_005c2bdd(iVar5,iVar5 + uVar3 * 4,iVar1);
        FUN_005c2c96(*param_2 + (param_1[1] - *param_1 >> 2) * 4,param_2[1],param_1[1],iVar2);
      }
      else {
        iVar5 = FUN_005c2bdd(iVar5,iVar2,iVar1);
        iVar1 = param_1[1];
        for (; iVar5 != iVar1; iVar5 = iVar5 + 4) {
          FUN_0042004f();
        }
      }
    }
    param_1[1] = *param_1 + uVar4 * 4;
  }
  return param_1;
}

