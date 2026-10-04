
int * __fastcall FUN_0041f169(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x2c) == *(int *)(param_1 + 0x28)) {
    iVar1 = FUN_0041f101();
    if (iVar1 != 0) {
      if ((*(uint *)(iVar1 + 0x14) >> 7 & 1) != 0) {
        FUN_005d4bbf(&DAT_006c12fc);
      }
      FUN_00412d8a(*(undefined4 *)(iVar1 + 0x24),*(undefined4 *)(iVar1 + 0x28));
    }
  }
  *(byte *)(param_1 + 0x40) = *(byte *)(param_1 + 0x40) & 0x7f;
  return (int *)(param_1 + 0x28);
}

