
void __thiscall FUN_005379e3(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  *(undefined4 *)(param_1 + 0xe4) = param_2;
  do {
    FUN_005e46f0(*(int *)(param_1 + 0xe4) == iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  return;
}

