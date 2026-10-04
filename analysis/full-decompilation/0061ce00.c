
void FUN_0061ce00(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  
  if ((*(int *)(param_1 + 0x234) != 0) && (*(int *)(param_1 + 0x270) != 0)) {
    iVar1 = *(int *)(param_1 + 0x254);
    piVar3 = *(int **)(iVar1 + 0x20);
    piVar7 = (int *)0x0;
    while (piVar2 = piVar3, piVar2 != (int *)0x0) {
      iVar6 = 0;
      piVar7 = piVar2;
      do {
        piVar7 = piVar7 + 1;
        if (*piVar7 == 0) {
          piVar2[iVar6 + 1] = param_2;
          return;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < 4);
      piVar7 = piVar2;
      piVar3 = (int *)*piVar2;
    }
    puVar5 = *(undefined4 **)(param_1 + 0x10280);
    *(undefined4 **)(param_1 + 0x10280) = puVar5 + 5;
    if (0x10000 < (int)(puVar5 + 5) - *(int *)(param_1 + 600)) {
      puVar4 = (undefined4 *)FUN_005a9320(0x10000);
      if (puVar4 == (undefined4 *)0x0) {
        FUN_00634c51("     \nOut of memory");
        FUN_00634c51(" - cross-reference disabled.\n");
        *(undefined4 *)(param_1 + 0x270) = 0;
        return;
      }
      **(undefined4 **)(param_1 + 600) = puVar4;
      *(undefined4 **)(param_1 + 600) = puVar4;
      *puVar4 = 0;
      puVar5 = puVar4 + 5;
      *(undefined4 **)(param_1 + 0x10280) = puVar4 + 10;
    }
    *puVar5 = 0;
    puVar5[1] = param_2;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = 0;
    if (piVar7 == (int *)0x0) {
      *(undefined4 **)(iVar1 + 0x20) = puVar5;
      return;
    }
    *piVar7 = (int)puVar5;
  }
  return;
}

