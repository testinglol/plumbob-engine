
void FUN_005825c5(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00401742(0xc);
  *puVar1 = 0;
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = *param_1;
    puVar1[2] = param_1[1];
  }
  return;
}

