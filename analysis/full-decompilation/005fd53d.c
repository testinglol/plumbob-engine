
void FUN_005fd53d(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00401742(8);
  *puVar1 = 0;
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = *param_1;
  }
  return;
}

