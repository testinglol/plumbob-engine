
void __thiscall FUN_005d1610(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_1[1];
  uVar2 = iVar1 - *param_1 >> 5;
  if (param_2 < uVar2) {
    FUN_0040812f(param_2 * 0x20 + *param_1,iVar1);
  }
  else {
    FUN_005d1855(iVar1,param_2 - uVar2,param_3);
  }
  return;
}

