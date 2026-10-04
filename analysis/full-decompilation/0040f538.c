
void __thiscall FUN_0040f538(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == *(int *)(param_1 + 8)) {
    FUN_0040f9f9(iVar1,param_2);
  }
  else {
    FUN_0040ff24();
    *(int *)(param_1 + 4) = iVar1 + 0x90;
  }
  return;
}

