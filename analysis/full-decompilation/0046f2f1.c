
undefined4 * __thiscall FUN_0046f2f1(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 local_5;
  
  FUN_0054821c(param_2[1] - *param_2 >> 2,&local_5);
  puVar3 = (undefined4 *)*param_2;
  puVar2 = (undefined4 *)*param_1;
  iVar4 = param_2[1] - (int)puVar3 >> 2;
  if (0 < iVar4) {
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
      *puVar2 = uVar1;
      puVar2 = puVar2 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  param_1[1] = puVar2;
  return param_1;
}

