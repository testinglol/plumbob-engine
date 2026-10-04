
void __thiscall FUN_00472b86(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  if (puVar2 == *(undefined4 **)(param_1 + 8)) {
    FUN_00472c6a(puVar2,param_2);
  }
  else {
    if (puVar2 != (undefined4 *)0x0) {
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = *param_2;
        param_2 = param_2 + 1;
        puVar2 = puVar2 + 1;
      }
    }
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x14;
  }
  return;
}

