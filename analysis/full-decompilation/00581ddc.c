
uint __thiscall FUN_00581ddc(int param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2 == 0) {
    uVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
    uVar1 = 0;
  }
  else {
    uVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
    uVar1 = *(uint *)(param_2 + 4) / uVar2;
    uVar2 = *(uint *)(param_2 + 4) % uVar2;
  }
  if (param_4 == 0) {
    uVar3 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
  }
  else {
    uVar3 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
    uVar1 = *(uint *)(param_4 + 4) / uVar3;
    uVar3 = *(uint *)(param_4 + 4) % uVar3;
  }
  if (param_2 != param_4) {
    if (uVar2 == uVar3) {
      uVar1 = FUN_00576e9a(uVar2,param_2,param_4);
    }
    else {
      FUN_00576e9a(uVar2,param_2,0);
      while (uVar2 = uVar2 + 1, uVar2 < uVar3) {
        FUN_005829f6(uVar2,0);
      }
      uVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
      if (uVar3 != uVar1) {
        uVar1 = FUN_005829f6(uVar3,param_4);
      }
    }
  }
  return uVar1;
}

