
undefined4 * FUN_0041ffd9(uint param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_006e48d4;
  if (DAT_006e48d4 == (undefined4 *)0x0) {
    FUN_0041e6df();
    puVar2 = DAT_006e48d4;
  }
  DAT_006e48d4 = (undefined4 *)*puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = param_1;
    pvVar1 = operator_new(param_1);
    *puVar2 = pvVar1;
    if (pvVar1 != (void *)0x0) {
      return puVar2;
    }
    *puVar2 = DAT_006e48d4;
    DAT_006e48d4 = puVar2;
  }
  return (undefined4 *)0x0;
}

