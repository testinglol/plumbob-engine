
void FUN_00418267(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  while (param_1 != (undefined4 *)0x0) {
    while (puVar1 = (undefined4 *)param_1[2], puVar1 != (undefined4 *)0x0) {
      param_1[2] = *puVar1;
      FUN_006321f0(puVar1);
    }
    puVar1 = (undefined4 *)*param_1;
    FUN_006321f0(param_1);
    param_1 = puVar1;
  }
  return;
}

