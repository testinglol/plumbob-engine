
void __fastcall FUN_0042d51d(int param_1)

{
  int *piVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint local_8;
  
  if (((*(byte *)(DAT_006e486c + 0x66) & 0x40) != 0) && (*(char *)(param_1 + 0x1a6) != '\x01')) {
    local_8 = 0;
    bVar2 = false;
    if (*(int *)(param_1 + 0x158) - *(int *)(param_1 + 0x154) >> 2 != 0) {
      piVar1 = *(int **)(param_1 + 0x154);
      piVar3 = piVar1;
      do {
        if (*(int *)(*piVar3 + 0x10c) == 0x157c) {
          bVar2 = true;
        }
        local_8 = local_8 + 1;
        piVar3 = piVar3 + 1;
      } while (local_8 < (uint)(*(int *)(param_1 + 0x158) - *(int *)(param_1 + 0x154) >> 2));
      if (bVar2) {
        iVar4 = 0;
        uVar5 = 0;
        piVar3 = piVar1;
        if (*(int *)(param_1 + 0x158) - *(int *)(param_1 + 0x154) >> 2 != 0) {
          do {
            if (iVar4 < *(int *)(*piVar3 + 0x10c)) {
              iVar4 = *(int *)(*piVar3 + 0x10c);
            }
            uVar5 = uVar5 + 1;
            piVar3 = piVar3 + 1;
          } while (uVar5 < (uint)(*(int *)(param_1 + 0x158) - *(int *)(param_1 + 0x154) >> 2));
        }
        *(int *)(piVar1[local_8] + 0x10c) = iVar4 + 1;
      }
    }
    FUN_0042d1d5(0x12);
    *(undefined1 *)(param_1 + 0x1a7) = 0;
    *(undefined1 *)(param_1 + 0x1a6) = 1;
    if (1 < (uint)(*(int *)(param_1 + 0x158) - *(int *)(param_1 + 0x154) >> 2)) {
      FUN_0042feee(*(undefined4 *)(param_1 + 0x154),*(undefined4 *)(param_1 + 0x158),&LAB_00425253);
    }
    FUN_00425316(*(undefined4 *)(DAT_006e486c + 0x44));
  }
  return;
}

