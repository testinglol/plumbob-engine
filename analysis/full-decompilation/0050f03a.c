
undefined4 __thiscall FUN_0050f03a(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 == 1) {
    if (param_3 == *(int *)(param_1 + 0x10c)) {
      FUN_005dac30(0x10,param_1,0);
      return 1;
    }
    param_2 = 1;
  }
  else if (param_2 == 0x15) {
    iVar1 = param_3 * 2 + 2;
    if ((iVar1 < 1) || (iVar2 = FUN_0047168f(), iVar2 < iVar1)) {
      (**(code **)(**(int **)(param_1 + 0x110) + 0x1a0))(&DAT_006c107c);
    }
    else {
      iVar2 = **(int **)(param_1 + 0x110);
      uVar3 = FUN_004705f2(iVar1,0xffffffff);
      (**(code **)(iVar2 + 0x1a0))(uVar3);
      (**(code **)(*(int *)(*(int *)(param_1 + 0x110) + 0xd4) + 0x1c))(0);
    }
    return 1;
  }
  uVar3 = FUN_005dd97f(param_2,param_3);
  return uVar3;
}

