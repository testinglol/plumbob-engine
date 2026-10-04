
undefined4 __thiscall FUN_00580664(char *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (*param_1 == '\0') {
    *(undefined4 *)(param_1 + 8) = param_3;
    *(char **)(param_1 + 0xc) = param_1 + 0x1c;
    *(char **)(param_1 + 0xa8) = param_1 + 0x44;
    *(int *)(param_1 + 4) = param_2;
    param_1[0x18] = '\0';
    if (0 < param_2) {
      do {
        *(undefined4 *)(*(int *)(param_1 + 0xc) + iVar1 * 4) = 0x80000000;
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 4));
    }
  }
  *param_1 = '\x01';
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}

