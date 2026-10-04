
void __thiscall FUN_004eb2de(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == *(int *)(param_1 + 8)) {
    FUN_004eb570(iVar1,param_2);
  }
  else {
    FUN_004eb8eb();
    *(int *)(param_1 + 4) = iVar1 + 0x1c;
  }
  return;
}

