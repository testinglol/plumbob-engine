
void FUN_0046de1b(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_00401742(0x1c);
  if ((undefined4 *)(iVar1 + 8) != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)(iVar1 + 8);
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *param_1;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}

