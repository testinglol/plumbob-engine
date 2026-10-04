
void __thiscall FUN_0041d8f0(int param_1,undefined4 *param_2,short *param_3)

{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)
                 (*(int *)(param_1 + 4) +
                 ((uint)(int)*param_3 % (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2))
                 * 4);
      (puVar1 != (undefined4 *)0x0 &&
      ((*(short *)(puVar1 + 1) != *param_3 || (*(char *)((int)puVar1 + 6) != (char)param_3[1]))));
      puVar1 = (undefined4 *)*puVar1) {
  }
  *param_2 = puVar1;
  param_2[1] = param_1;
  return;
}

