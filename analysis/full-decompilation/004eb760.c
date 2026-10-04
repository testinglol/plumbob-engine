
undefined4 * __thiscall FUN_004eb760(undefined4 *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  *param_1 = *param_2;
  puVar2 = param_1 + 3;
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)(param_2 + 1);
  param_1[2] = param_2[2];
  iVar3 = ((int)puVar2 - (int)param_1) + (int)param_2;
  param_2 = (undefined4 *)0x7;
  do {
    FUN_005a5dcc(iVar3);
    puVar1 = (undefined1 *)(iVar3 + 4);
    iVar3 = iVar3 + 8;
    *(undefined1 *)(puVar2 + 1) = *puVar1;
    puVar2 = puVar2 + 2;
    param_2 = (undefined4 *)((int)param_2 + -1);
  } while (param_2 != (undefined4 *)0x0);
  return param_1;
}

