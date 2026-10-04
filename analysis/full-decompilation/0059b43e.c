
void __thiscall FUN_0059b43e(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_1[1];
  uVar2 = (iVar1 - *param_1) / 0x18;
  if (param_2 < uVar2) {
    FUN_0059b47a(*param_1 + param_2 * 0x18,iVar1);
  }
  else {
    FUN_0059c7a0(iVar1,param_2 - uVar2,param_3);
  }
  return;
}

