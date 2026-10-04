
undefined4 * __thiscall FUN_00472be0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_2 + 3 != *(undefined4 **)(param_1 + 4)) &&
     (iVar1 = ((int)*(undefined4 **)(param_1 + 4) - (int)(param_2 + 3)) / 0xc, puVar2 = param_2,
     0 < iVar1)) {
    do {
      iVar1 = iVar1 + -1;
      *puVar2 = puVar2[3];
      puVar2[1] = puVar2[4];
      puVar2[2] = puVar2[5];
      puVar2 = puVar2 + 3;
    } while (iVar1 != 0);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -0xc;
  return param_2;
}

