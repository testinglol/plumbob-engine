
void __fastcall FUN_0042c141(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint local_8;
  
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x20) != 0) {
    if (*(char *)(param_1 + 0x1aa) != '\0') {
      uVar4 = 0;
      local_8 = 0;
      if (*(int *)(param_1 + 0x158) - *(int *)(param_1 + 0x154) >> 2 != 0) {
        piVar1 = *(int **)(param_1 + 0x154);
        piVar2 = piVar1;
LAB_0042c184:
        if (*(int *)(*piVar2 + 0x10c) != 4000) goto code_r0x0042c192;
        iVar3 = 0;
        piVar2 = piVar1;
        if (*(int *)(param_1 + 0x158) - *(int *)(param_1 + 0x154) >> 2 != 0) {
          do {
            if (iVar3 < *(int *)(*piVar2 + 0x10c)) {
              iVar3 = *(int *)(*piVar2 + 0x10c);
            }
            uVar4 = uVar4 + 1;
            piVar2 = piVar2 + 1;
          } while (uVar4 < (uint)(*(int *)(param_1 + 0x158) - *(int *)(param_1 + 0x154) >> 2));
        }
        *(int *)(piVar1[local_8] + 0x10c) = iVar3 + 1;
      }
LAB_0042c1f5:
      FUN_0042bce6();
      *(undefined1 *)(param_1 + 0x1aa) = 0;
    }
    FUN_00425316(*(undefined4 *)(DAT_006e486c + 0x44));
  }
  return;
code_r0x0042c192:
  local_8 = local_8 + 1;
  piVar2 = piVar2 + 1;
  if ((uint)(*(int *)(param_1 + 0x158) - *(int *)(param_1 + 0x154) >> 2) <= local_8)
  goto LAB_0042c1f5;
  goto LAB_0042c184;
}

