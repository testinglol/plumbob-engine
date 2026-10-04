
void __fastcall FUN_005e9d7d(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x50) == *(int *)(param_1 + 0x4c)) {
    return;
  }
  iVar2 = *(int *)(param_1 + 0x100);
  if (iVar2 == 0) {
LAB_005e9df7:
    piVar1 = (int *)(param_1 + 0xe4);
    *piVar1 = *(int *)(param_1 + 0x7c);
    *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 0x80);
    *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 0x84);
    *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_1 + 0x88);
    iVar2 = *(int *)(param_1 + 0xdc);
    *(int *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) + *(int *)(param_1 + 0xe0);
    *piVar1 = *piVar1 + iVar2;
    *(int *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) - iVar2;
    *(int *)(param_1 + 0xf0) = *(int *)(param_1 + 0xf0) - *(int *)(param_1 + 0xe0);
    FUN_005df565(*(int *)(param_1 + 0xdc),*(undefined4 *)(param_1 + 0xe0));
  }
  else {
    if (iVar2 != 1) {
      if (iVar2 == 2) goto LAB_005e9df7;
      if (iVar2 != 3) {
        if (iVar2 == 4) goto LAB_005e9df7;
        if (iVar2 != 5) {
          return;
        }
      }
    }
    FUN_005e9e6e((int *)(param_1 + 0xe4));
    FUN_005df565(*(undefined4 *)(param_1 + 0xdc),
                 (((*(int *)(param_1 + 0xe8) - *(int *)(param_1 + 0xf0)) - *(int *)(param_1 + 0x80))
                 + *(int *)(param_1 + 0x88)) / 2);
    *(int *)(param_1 + 0xec) =
         ((*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0xdc)) - *(int *)(param_1 + 0x7c)) +
         *(int *)(param_1 + 0xe4);
  }
  return;
}

