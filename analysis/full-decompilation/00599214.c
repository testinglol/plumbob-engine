
void __fastcall FUN_00599214(int param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_8;
  
  if (*(int *)(param_1 + 0x94) != 0) {
    iVar5 = *(int *)(param_1 + 0x68) - *(int *)(param_1 + 100) >> 2;
    iVar6 = *(int *)(param_1 + 0x80) - *(int *)(param_1 + 0x7c) >> 2;
    if (iVar6 != 0) {
      do {
        bVar2 = true;
        local_8 = 1;
        iVar4 = **(int **)(param_1 + 0x7c);
        if (iVar6 < 2) break;
        do {
          piVar1 = (int *)(*(int *)(param_1 + 0x7c) + local_8 * 4);
          iVar3 = *piVar1;
          if (*(int *)(iVar3 + 0x14) < *(int *)(iVar4 + 0x14)) {
            bVar2 = false;
            piVar1[-1] = iVar3;
            *(int *)(*(int *)(param_1 + 0x7c) + local_8 * 4) = iVar4;
            iVar3 = iVar4;
          }
          local_8 = local_8 + 1;
          iVar4 = iVar3;
        } while (local_8 < iVar6);
      } while (!bVar2);
    }
    iVar4 = 0;
    if (0 < iVar5) {
      do {
        iVar3 = iVar4 * 4;
        iVar4 = iVar4 + 1;
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 100) + iVar3) + 0x68) = 0xffffd8f0;
      } while (iVar4 < iVar5);
    }
    iVar5 = 0;
    if (0 < iVar6) {
      do {
        FUN_00597c25();
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar6);
    }
    *(undefined4 *)(param_1 + 0x94) = 0;
  }
  return;
}

