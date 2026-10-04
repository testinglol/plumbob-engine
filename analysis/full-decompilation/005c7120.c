
undefined4 * FUN_005c7120(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = (param_2 - param_1) / 0x18;
  if (0 < iVar4) {
    puVar2 = (undefined4 *)(param_2 + 0x10);
    puVar3 = param_3 + 4;
    do {
      puVar1 = (undefined4 *)(param_2 + -0x18);
      param_2 = param_2 + -0x18;
      param_3 = param_3 + -6;
      iVar4 = iVar4 + -1;
      *param_3 = *puVar1;
      puVar3[-9] = puVar2[-9];
      puVar3[-8] = puVar2[-8];
      puVar3[-7] = puVar2[-7];
      puVar3[-6] = puVar2[-6];
      *(undefined2 *)(puVar3 + -5) = *(undefined2 *)(puVar2 + -5);
      puVar2 = puVar2 + -6;
      puVar3 = puVar3 + -6;
    } while (iVar4 != 0);
    return param_3;
  }
  return param_3;
}

