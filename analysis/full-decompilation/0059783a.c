
undefined4 __thiscall FUN_0059783a(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2;
  if (0 < iVar3) {
    do {
      cVar1 = FUN_004317d5(*(undefined4 *)(*(int *)(param_1 + 0x20) + iVar2 * 4),param_2);
      if (cVar1 != '\0') {
        return *(undefined4 *)(*(int *)(param_1 + 0x20) + iVar2 * 4);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  return 0;
}

