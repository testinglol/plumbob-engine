
void __thiscall FUN_00531f19(int param_1,char param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0xdc) >> 2 != 0) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0xdc) + uVar2 * 4);
      if (DAT_006d74f0 == 0) {
        *(undefined4 *)(iVar1 + 0x154) = 0;
      }
      else {
        *(int *)(iVar1 + 0x158) = DAT_006d74f0;
        *(uint *)(iVar1 + 0x154) = (uint)(param_2 != '\0');
      }
      *(undefined1 *)(iVar1 + 0x16c) = 0;
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0xdc) >> 2));
  }
  return;
}

