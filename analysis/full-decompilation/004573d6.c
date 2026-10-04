
undefined4 __fastcall FUN_004573d6(int param_1)

{
  short sVar1;
  int iVar2;
  
  sVar1 = *(short *)(*(int *)(param_1 + 0x60) + 0xe);
  if (sVar1 < 0) {
    if (sVar1 == -1) {
      iVar2 = FUN_004573f9();
      return CONCAT22((short)((uint)*(int *)(iVar2 + 0x60) >> 0x10),
                      *(undefined2 *)(*(int *)(iVar2 + 0x60) + 0xe));
    }
    sVar1 = 0;
  }
  return CONCAT22((short)((uint)*(int *)(param_1 + 0x60) >> 0x10),sVar1);
}

