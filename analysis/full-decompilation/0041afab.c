
int * __thiscall FUN_0041afab(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (param_2 != param_1) {
    iVar2 = param_2[1];
    iVar3 = *param_2;
    uVar1 = (iVar2 - iVar3) / 0x5c;
    if ((uint)((param_1[2] - *param_1) / 0x5c) < uVar1) {
      iVar2 = FUN_0041b50f(uVar1,iVar3,iVar2);
      iVar3 = (param_1[2] - *param_1) / 0x5c;
      if (iVar3 != 0) {
        FUN_0040189d(*param_1,iVar3 * 0x5c);
      }
      *param_1 = iVar2;
      param_1[2] = uVar1 * 0x5c + iVar2;
    }
    else {
      uVar4 = (param_1[1] - *param_1) / 0x5c;
      if (uVar4 < uVar1) {
        FUN_0041ad98(iVar3,uVar4 * 0x5c + iVar3,*param_1);
        FUN_0041b6de(((param_1[1] - *param_1) / 0x5c) * 0x5c + *param_2,param_2[1],param_1[1],uVar1)
        ;
      }
      else {
        FUN_0041ad98(iVar3,iVar2,*param_1);
      }
    }
    param_1[1] = uVar1 * 0x5c + *param_1;
  }
  return param_1;
}

