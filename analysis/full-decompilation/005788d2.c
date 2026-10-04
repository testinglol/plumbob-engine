
undefined4 __thiscall FUN_005788d2(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_8;
  
  if (*(char *)(param_1 + 4) != '\0') {
    local_8 = 0;
    *(int **)(param_1 + 0x28) = param_2;
    iVar1 = *(int *)(param_1 + 0x34);
    if (0 < *(int *)(iVar1 + 0x24)) {
      param_2 = (int *)(param_1 + 0x94);
      do {
        iVar2 = 0;
        piVar3 = param_2;
        if (0 < *(int *)(iVar1 + 0x28)) {
          do {
            if (*(int *)(*piVar3 + 8) == 4) {
              FUN_00579f5b(*(undefined4 *)(param_1 + 0x28));
            }
            iVar2 = iVar2 + 1;
            piVar3 = piVar3 + 1;
          } while (iVar2 < *(int *)(*(int *)(param_1 + 0x34) + 0x28));
        }
        local_8 = local_8 + 1;
        iVar1 = *(int *)(param_1 + 0x34);
        param_2 = param_2 + 0x40;
      } while (local_8 < *(int *)(iVar1 + 0x24));
    }
  }
  return 1;
}

