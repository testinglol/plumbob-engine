
uint __fastcall FUN_0046e120(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x10);
  if (0 < (int)uVar3) {
    uVar3 = uVar3 - 1;
    *(uint *)(param_1 + 0x10) = uVar3;
  }
  if ((*(int *)(param_1 + 0x10) != 0) &&
     (*(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1, *(int *)(param_1 + 0x28) == 0xc)) {
    piVar1 = (int *)(param_1 + 0x20);
    *piVar1 = *piVar1 + *(int *)(param_1 + 0x24);
    if (*piVar1 < 0) {
      do {
        piVar1 = (int *)(param_1 + 0x20);
        *piVar1 = *piVar1 + *(int *)(param_1 + 0x1c);
      } while (*piVar1 < 0);
    }
    iVar2 = *(int *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(int *)(param_1 + 0x20) = iVar2 % *(int *)(param_1 + 0x1c);
    return CONCAT31((int3)((uint)(iVar2 / *(int *)(param_1 + 0x1c)) >> 8),1);
  }
  return uVar3 & 0xffffff00;
}

