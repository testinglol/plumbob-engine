
void __thiscall FUN_00534230(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_1[1];
  uVar2 = (iVar1 - *param_1) / 0x28;
  if (param_2 < uVar2) {
    FUN_005342e9(*param_1 + param_2 * 0x28,iVar1);
  }
  else {
    FUN_00534461(iVar1,param_2 - uVar2,param_3);
  }
  return;
}

