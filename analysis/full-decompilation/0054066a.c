
void __thiscall FUN_0054066a(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int local_8;
  
  local_8 = 2;
  *(undefined4 *)(param_1 + 4) = param_2;
  puVar2 = (undefined4 *)(param_1 + 8);
  do {
    piVar1 = (int *)puVar2[2];
    for (iVar3 = *piVar1; iVar3 != piVar1[1]; iVar3 = iVar3 + 4) {
      FUN_0053daef(param_2);
      piVar1 = (int *)puVar2[2];
    }
    piVar1 = (int *)*puVar2;
    for (iVar3 = *piVar1; iVar3 != piVar1[1]; iVar3 = iVar3 + 4) {
      FUN_0053c29b(param_2);
      piVar1 = (int *)*puVar2;
    }
    puVar2 = puVar2 + 1;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  FUN_005409be(0);
  return;
}

