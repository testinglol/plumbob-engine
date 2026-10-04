
undefined4 * __fastcall FUN_0059478f(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
    *puVar1 = param_1;
    return puVar1;
  }
  return (undefined4 *)0x0;
}

