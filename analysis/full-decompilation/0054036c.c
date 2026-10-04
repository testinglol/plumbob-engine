
undefined1 * FUN_0054036c(int param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  undefined2 *puVar2;
  
  iVar1 = (param_2 - param_1) / 6;
  if (0 < iVar1) {
    puVar2 = (undefined2 *)(param_1 + 2);
    param_1 = (int)param_3 - param_1;
    do {
      param_3[1] = *(undefined1 *)((int)puVar2 + -1);
      *(undefined2 *)(param_1 + (int)puVar2) = *puVar2;
      *(undefined2 *)(param_3 + 4) = puVar2[1];
      *param_3 = *(undefined1 *)(puVar2 + -1);
      param_3 = param_3 + 6;
      puVar2 = puVar2 + 3;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_3;
}

