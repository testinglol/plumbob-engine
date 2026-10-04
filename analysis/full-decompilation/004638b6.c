
void __thiscall FUN_004638b6(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  
  FUN_00423256(param_2,param_3,param_4);
  if (0xe < param_3) {
    piVar1 = (int *)(param_1 + 0x1ac);
    param_4 = *(int *)(param_1 + 0x1b0) - *piVar1 >> 2;
    FUN_00464a4e(&param_4,1);
    while (param_4 < (uint)(*(int *)(param_1 + 0x1b0) - *piVar1 >> 2)) {
      FUN_0042ec52(*(int *)(param_1 + 0x1b0) + -4);
    }
    while ((uint)(*(int *)(param_1 + 0x1b0) - *piVar1 >> 2) < param_4) {
      param_2 = 0;
      FUN_00464260(&param_2);
    }
    if (param_3 < 0x26) {
      iVar2 = 0;
      if (0 < (int)param_4) {
        do {
          param_3 = 0;
          FUN_00464a4e(&param_3,1);
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)param_4);
      }
    }
    else {
      FUN_00464b48(*piVar1,param_4);
    }
  }
  return;
}

