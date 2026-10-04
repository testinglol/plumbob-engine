
void FUN_00619f40(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_retaddr;
  
  FUN_00619f60(param_1);
  FUN_0063a8a3(param_2);
  FUN_00637cca(10);
  if (unaff_retaddr != 0) {
    if (*(int *)(unaff_retaddr + 0x10284) != 0) {
      FUN_005a9340(*(int *)(unaff_retaddr + 0x10284));
    }
    if (*(int *)(unaff_retaddr + 0x10278) != 0) {
      FUN_005a9340(*(int *)(unaff_retaddr + 0x10278));
    }
    iVar3 = *(int *)(unaff_retaddr + 0x10274);
    while (iVar3 != 0) {
      iVar3 = **(int **)(unaff_retaddr + 0x10274);
      FUN_005a9340(*(int **)(unaff_retaddr + 0x10274));
      *(int *)(unaff_retaddr + 0x10274) = iVar3;
    }
    if (*(int *)(unaff_retaddr + 0x260) != 0) {
      FUN_005a9340(*(int *)(unaff_retaddr + 0x260));
    }
    if (*(int *)(unaff_retaddr + 0x102b8) != 0) {
      FUN_005a9340(*(int *)(unaff_retaddr + 0x102b8));
    }
    if (*(int *)(unaff_retaddr + 0x102c0) != 0) {
      puVar4 = *(undefined4 **)(unaff_retaddr + 0x102c4);
      puVar1 = puVar4 + 2;
      do {
        if ((HMODULE)*puVar1 != (HMODULE)0x0) {
          puVar4 = *(undefined4 **)(unaff_retaddr + 0x102c4);
          FreeLibrary((HMODULE)*puVar1);
        }
        iVar3 = *(int *)(unaff_retaddr + 0x102c0) + -1;
        *(int *)(unaff_retaddr + 0x102c0) = iVar3;
        puVar2 = puVar4 + iVar3 * 3;
        *puVar4 = *puVar2;
        puVar4[1] = puVar2[1];
        puVar4[2] = puVar2[2];
      } while (iVar3 != 0);
    }
    if (*(int *)(unaff_retaddr + 0x102c4) != 0) {
      FUN_005a9340(*(int *)(unaff_retaddr + 0x102c4));
    }
    FUN_0061a050(*(undefined4 *)(unaff_retaddr + 0x102bc));
    FUN_005a9340(unaff_retaddr);
  }
  return;
}

