
undefined4 __thiscall FUN_00580558(char *param_1,int param_2,undefined4 param_3)

{
  void *pvVar1;
  int iVar2;
  
  if (*param_1 == '\0') {
    *(int *)(param_1 + 4) = param_2;
    *(undefined4 *)(param_1 + 8) = param_3;
    pvVar1 = operator_new(param_2 << 2);
    *(void **)(param_1 + 0xc) = pvVar1;
    iVar2 = 0;
    param_1[0x18] = '\x01';
    if (0 < *(int *)(param_1 + 4)) {
      do {
        *(undefined4 *)(*(int *)(param_1 + 0xc) + iVar2 * 4) = 0;
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(param_1 + 4));
    }
  }
  *param_1 = '\x01';
  return 1;
}

