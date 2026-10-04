
void __fastcall FUN_005476fc(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x180) + *(int *)(param_1 + 0x178) * 2;
  *(undefined4 *)(param_1 + 0x174) = *(undefined4 *)(param_1 + 0x1e8 + iVar1 * 8);
  *(undefined4 *)(param_1 + 0x170) = *(undefined4 *)(param_1 + 0x1ec + iVar1 * 8);
  return;
}

