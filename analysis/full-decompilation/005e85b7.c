
void FUN_005e85b7(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00401742(0x1c);
  if ((undefined4 *)(iVar1 + 0x10) != (undefined4 *)0x0) {
    *(undefined4 *)(iVar1 + 0x10) = *param_1;
    *(undefined4 *)(iVar1 + 0x14) = param_1[1];
    *(undefined4 *)(iVar1 + 0x18) = param_1[2];
  }
  return;
}

