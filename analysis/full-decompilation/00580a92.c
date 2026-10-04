
void __thiscall FUN_00580a92(int param_1,int *param_2)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2 != 0) {
    piVar2 = *(int **)(param_1 + 4);
    do {
      if (*piVar2 != 0) {
        *param_2 = (*(int **)(param_1 + 4))[uVar1];
        goto LAB_00580ac3;
      }
      uVar1 = uVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (uVar1 < (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2));
  }
  *param_2 = 0;
LAB_00580ac3:
  param_2[1] = param_1;
  return;
}

