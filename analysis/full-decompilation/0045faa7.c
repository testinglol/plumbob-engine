
undefined4 * __thiscall FUN_0045faa7(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  if ((param_2 + 3 != puVar1) &&
     (iVar2 = ((int)puVar1 - (int)(param_2 + 3)) / 0xc, puVar3 = param_2, 0 < iVar2)) {
    do {
      iVar2 = iVar2 + -1;
      *puVar3 = puVar3[3];
      puVar3[1] = puVar3[4];
      puVar3[2] = puVar3[5];
      puVar3 = puVar3 + 3;
    } while (iVar2 != 0);
  }
  *(undefined4 **)(param_1 + 4) = puVar1 + -3;
  return param_2;
}

