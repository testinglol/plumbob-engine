
void FUN_005c25fa(int param_1)

{
  int iVar1;
  
  while (param_1 != 0) {
    FUN_005c25fa(*(undefined4 *)(param_1 + 0xc));
    iVar1 = *(int *)(param_1 + 8);
    FUN_005c29fc(param_1);
    param_1 = iVar1;
  }
  return;
}

