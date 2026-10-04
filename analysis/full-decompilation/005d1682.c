
void __thiscall FUN_005d1682(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_1[1];
  uVar2 = iVar1 - *param_1 >> 3;
  if (param_2 < uVar2) {
    FUN_004a1827(*param_1 + param_2 * 8,iVar1);
  }
  else {
    FUN_005d1c60(iVar1,param_2 - uVar2,param_3);
  }
  return;
}

