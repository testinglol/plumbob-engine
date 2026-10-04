
void __thiscall FUN_00580ad6(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_1[1];
  uVar2 = iVar1 - *param_1 >> 2;
  if (param_2 < uVar2) {
    FUN_004071be(*param_1 + param_2 * 4,iVar1);
  }
  else {
    FUN_00581731(iVar1,param_2 - uVar2,param_3);
  }
  return;
}

