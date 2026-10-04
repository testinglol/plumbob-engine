
void __fastcall FUN_0048b833(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x2c);
  if (iVar1 != 0) {
    uVar2 = CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0xf0));
    FUN_00492b05(uVar2);
    FUN_0044127f(uVar2);
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return;
}

