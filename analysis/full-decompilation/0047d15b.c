
void __thiscall FUN_0047d15b(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_1[1];
  uVar2 = iVar1 - *param_1 >> 2;
  if (param_2 < uVar2) {
    FUN_0047d4e0(*param_1 + param_2 * 4,iVar1);
  }
  else {
    FUN_0047d68f(iVar1,param_2 - uVar2,param_3);
  }
  return;
}

