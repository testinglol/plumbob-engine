
void FUN_004c90d0(int *param_1)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = param_1;
  FUN_004730c5(param_1);
  puVar1 = (uint *)(param_1 + 1);
  if (*param_1 < 0x1f6) {
    FUN_004730c5(puVar1);
    param_1 = (int *)0x0;
    if (*puVar1 != 0) {
      piVar3 = piVar2 + 2;
      do {
        FUN_004730c5(piVar3);
        FUN_00473111(*piVar3 + (int)piVar2);
        param_1 = (int *)((int)param_1 + 1);
        piVar3 = piVar3 + 1;
      } while (param_1 < *puVar1);
    }
  }
  else {
    FUN_004730c5(puVar1);
    FUN_004730c5(param_1 + 2);
    param_1 = (int *)0x0;
    if (*puVar1 != 0) {
      piVar3 = piVar2 + 3;
      do {
        FUN_004730c5(piVar3);
        FUN_00473111(*piVar3 + (int)piVar2);
        param_1 = (int *)((int)param_1 + 1);
        piVar3 = piVar3 + 1;
      } while (param_1 < *puVar1);
    }
  }
  return;
}

