
void __thiscall FUN_005d1646(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_1[1];
  uVar2 = (iVar1 - *param_1) / 0xc;
  if (param_2 < uVar2) {
    FUN_005d16b6(*param_1 + param_2 * 0xc,iVar1);
  }
  else {
    FUN_005d1a34(iVar1,param_2 - uVar2,param_3);
  }
  return;
}

