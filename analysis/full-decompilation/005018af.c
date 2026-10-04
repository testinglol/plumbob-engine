
void __thiscall FUN_005018af(int param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  if (param_2 == '\0') {
    *(undefined1 *)(param_1 + 0x178) = 0;
    uVar3 = 0;
    if (*(int *)(param_1 + 0x128) - *(int *)(param_1 + 0x124) >> 2 != 0) {
      do {
        piVar2 = (int *)FUN_00492d2c();
        (**(code **)(*piVar2 + 0x94))();
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uint)(*(int *)(param_1 + 0x128) - *(int *)(param_1 + 0x124) >> 2));
    }
    (**(code **)(**(int **)(param_1 + 0x174) + 0x98))();
  }
  else {
    *(undefined1 *)(param_1 + 0x178) = 1;
    uVar3 = 0;
    if (*(int *)(param_1 + 0x128) - *(int *)(param_1 + 0x124) >> 2 != 0) {
      do {
        if (*(int *)(*(int *)(param_1 + 0x124) + uVar3 * 4) != 0) {
          iVar1 = FUN_00492d2c();
          if (iVar1 != 0) {
            piVar2 = (int *)FUN_00492d2c();
            (**(code **)(*piVar2 + 0x98))();
          }
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uint)(*(int *)(param_1 + 0x128) - *(int *)(param_1 + 0x124) >> 2));
    }
    if (*(int **)(param_1 + 0xec) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0xec) + 0x98))();
    }
    if (*(int **)(param_1 + 0xf0) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0xf0) + 0x98))();
    }
    (**(code **)(**(int **)(param_1 + 0x174) + 0x94))();
    FUN_0052a21f(*(undefined4 *)(param_1 + 0xd4));
  }
  return;
}

