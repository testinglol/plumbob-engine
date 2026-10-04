
void __thiscall FUN_004b048c(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x7c);
  if ((-1 < iVar1) && (iVar1 < 2)) {
    *(undefined4 *)(param_1 + 0x7c) = 3;
    FUN_004b04af(*(undefined4 *)(param_1 + 0x70 + iVar1 * 4),param_2);
  }
  return;
}

