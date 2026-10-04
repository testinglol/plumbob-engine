
void __thiscall FUN_00575b11(int param_1,undefined4 *param_2,uint *param_3)

{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)
                 (*(int *)(param_1 + 4) +
                 (*param_3 % (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2)) * 4);
      (puVar1 != (undefined4 *)0x0 && (puVar1[1] != *param_3)); puVar1 = (undefined4 *)*puVar1) {
  }
  *param_2 = puVar1;
  param_2[1] = param_1;
  return;
}

