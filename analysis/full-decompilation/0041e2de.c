
undefined4 * __thiscall FUN_0041e2de(int param_1,undefined4 *param_2,uint *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = (*param_3 % (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2)) * 4;
  puVar1 = *(undefined4 **)(iVar3 + *(int *)(param_1 + 4));
  puVar2 = puVar1;
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)FUN_0041e80d(param_3);
      *puVar2 = puVar1;
      *(undefined4 **)(iVar3 + *(int *)(param_1 + 4)) = puVar2;
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      *param_2 = puVar2;
      param_2[1] = param_1;
      *(undefined1 *)(param_2 + 2) = 1;
      return param_2;
    }
    if (puVar2[1] == *param_3) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  *(undefined1 *)(param_2 + 2) = 0;
  *param_2 = puVar2;
  param_2[1] = param_1;
  return param_2;
}

