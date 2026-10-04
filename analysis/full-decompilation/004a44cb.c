
int FUN_004a44cb(undefined1 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00401742(0x1c);
  if ((undefined1 *)(iVar1 + 0x10) != (undefined1 *)0x0) {
    *(undefined1 *)(iVar1 + 0x10) = *param_1;
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(param_1 + 8);
  }
  return iVar1;
}

