
void FUN_0057a12b(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00401742(0x10);
  if ((undefined4 *)(iVar1 + 8) != (undefined4 *)0x0) {
    *(undefined4 *)(iVar1 + 8) = *param_1;
    *(undefined4 *)(iVar1 + 0xc) = param_1[1];
  }
  return;
}

