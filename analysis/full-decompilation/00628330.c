
void FUN_00628330(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x10284) != 0) {
      FUN_005a9340(*(int *)(param_1 + 0x10284));
    }
    if (*(int *)(param_1 + 0x10278) != 0) {
      FUN_005a9340(*(int *)(param_1 + 0x10278));
    }
    iVar3 = *(int *)(param_1 + 0x10274);
    while (iVar3 != 0) {
      iVar3 = **(int **)(param_1 + 0x10274);
      FUN_005a9340(*(int **)(param_1 + 0x10274));
      *(int *)(param_1 + 0x10274) = iVar3;
    }
    if (*(int *)(param_1 + 0x260) != 0) {
      FUN_005a9340(*(int *)(param_1 + 0x260));
    }
    if (*(int *)(param_1 + 0x102b8) != 0) {
      FUN_005a9340(*(int *)(param_1 + 0x102b8));
    }
    if (*(int *)(param_1 + 0x102c0) != 0) {
      puVar4 = *(undefined4 **)(param_1 + 0x102c4);
      puVar1 = puVar4 + 2;
      do {
        if ((HMODULE)*puVar1 != (HMODULE)0x0) {
          puVar4 = *(undefined4 **)(param_1 + 0x102c4);
          FreeLibrary((HMODULE)*puVar1);
        }
        iVar3 = *(int *)(param_1 + 0x102c0) + -1;
        *(int *)(param_1 + 0x102c0) = iVar3;
        puVar2 = puVar4 + iVar3 * 3;
        *puVar4 = *puVar2;
        puVar4[1] = puVar2[1];
        puVar4[2] = puVar2[2];
      } while (iVar3 != 0);
    }
    if (*(int *)(param_1 + 0x102c4) != 0) {
      FUN_005a9340(*(int *)(param_1 + 0x102c4));
    }
    FUN_00628420(*(undefined4 *)(param_1 + 0x102bc));
    FUN_005a9340(param_1);
  }
  return;
}

