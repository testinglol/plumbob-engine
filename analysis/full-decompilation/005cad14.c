
undefined4 FUN_005cad14(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1[3] == 0x10) {
    uVar1 = 0;
    puVar3 = (undefined4 *)(*(int *)(param_2 + 0x99c) + -0x20);
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *param_1;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

