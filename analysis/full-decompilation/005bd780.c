
void __thiscall FUN_005bd780(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_1[1];
  uVar2 = iVar1 - *param_1 >> 1;
  if (param_2 < uVar2) {
    FUN_005bd82a(*param_1 + param_2 * 2,iVar1);
  }
  else {
    FUN_005bd8f8(iVar1,param_2 - uVar2,param_3);
  }
  return;
}

