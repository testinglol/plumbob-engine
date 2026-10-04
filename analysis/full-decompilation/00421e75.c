
int __fastcall FUN_00421e75(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1ac) == 0) {
    return 0;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x1ac) + 0x118);
  if (*(short *)(iVar1 + 0x14) != 0) {
    iVar1 = FUN_004573f9();
    return (int)*(short *)(*(int *)(iVar1 + 0x60) + 0x24);
  }
  return (int)*(short *)(iVar1 + 0x24);
}

