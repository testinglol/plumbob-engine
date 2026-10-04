
int FUN_00469548(undefined1 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00401742(0x24);
  if ((undefined1 *)(iVar1 + 0x10) != (undefined1 *)0x0) {
    *(undefined1 *)(iVar1 + 0x10) = *param_1;
    *(undefined1 *)(iVar1 + 0x11) = param_1[1];
    *(undefined1 *)(iVar1 + 0x12) = param_1[2];
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(param_1 + 0x10);
  }
  return iVar1;
}

