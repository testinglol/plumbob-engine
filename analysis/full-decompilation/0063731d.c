
int FUN_0063731d(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0063734b(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((*(byte *)(param_1 + 0xd) & 0x40) != 0) {
    iVar1 = FUN_00642888(*(undefined4 *)(param_1 + 0x10));
    return -(uint)(iVar1 != 0);
  }
  return 0;
}

