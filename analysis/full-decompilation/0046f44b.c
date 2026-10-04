
void FUN_0046f44b(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)0x0;
  if (param_1 != 0) {
    puVar1 = (undefined4 *)FUN_00401742(param_1 << 2);
  }
  iVar2 = param_3 - param_2 >> 2;
  if (0 < iVar2) {
    param_2 = param_2 - (int)puVar1;
    do {
      *puVar1 = *(undefined4 *)(param_2 + (int)puVar1);
      puVar1 = puVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

