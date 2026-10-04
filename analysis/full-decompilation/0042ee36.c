
undefined4 * __thiscall FUN_0042ee36(undefined4 *param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  
  *param_1 = 0;
  puVar1 = (undefined1 *)FUN_00401742(0x20);
  *(undefined4 *)(puVar1 + 4) = 0;
  *puVar1 = 0;
  param_1[1] = 0;
  *(undefined1 **)(puVar1 + 8) = puVar1;
  *param_1 = puVar1;
  *(undefined1 **)(puVar1 + 0xc) = puVar1;
  *(undefined1 *)(param_1 + 2) = *param_2;
  return param_1;
}

