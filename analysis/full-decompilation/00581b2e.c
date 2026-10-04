
void __thiscall FUN_00581b2e(int param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
  }
  else {
    uVar1 = FUN_00580d6d(param_2 + 4);
  }
  if (param_4 == 0) {
    uVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
  }
  else {
    uVar2 = FUN_00580d6d(param_4 + 4);
  }
  if (param_2 != param_4) {
    if (uVar1 == uVar2) {
      FUN_00582884(uVar1,param_2,param_4);
    }
    else {
      FUN_00582884(uVar1,param_2,0);
      while (uVar1 = uVar1 + 1, uVar1 < uVar2) {
        FUN_00582849(uVar1,0);
      }
      if (uVar2 != *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2) {
        FUN_00582849(uVar2,param_4);
      }
    }
  }
  return;
}

