
undefined4 * __thiscall FUN_00576349(int param_1,undefined4 *param_2,uint *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = (*param_3 % (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2)) * 4;
  puVar1 = *(undefined4 **)(iVar4 + *(int *)(param_1 + 4));
  puVar3 = puVar1;
  do {
    if (puVar3 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)FUN_005825c5(param_3);
      *puVar2 = puVar1;
      *(undefined4 **)(iVar4 + *(int *)(param_1 + 4)) = puVar2;
LAB_005763a8:
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      param_2[1] = param_1;
      *param_2 = puVar2;
      return param_2;
    }
    if (puVar3[1] == *param_3) {
      puVar2 = (undefined4 *)FUN_005825c5(param_3);
      *puVar2 = *puVar3;
      *puVar3 = puVar2;
      goto LAB_005763a8;
    }
    puVar3 = (undefined4 *)*puVar3;
  } while( true );
}

