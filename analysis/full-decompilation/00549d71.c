
void __thiscall FUN_00549d71(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x114);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xe8) - *(int *)(iVar1 + 0xe4) == 1)) {
    FUN_00436e16();
  }
  FUN_005e909a(param_2,param_3,param_4);
  return;
}

