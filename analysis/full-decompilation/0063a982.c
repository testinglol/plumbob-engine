
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_0063a982(undefined1 *param_1)

{
  uint uVar1;
  undefined1 *puVar2;
  
  FUN_0063cf0c(0,&PTR_DAT_006dae30);
  puVar2 = param_1;
  while( true ) {
    _DAT_006dae34 = _DAT_006dae34 + -1;
    if (_DAT_006dae34 < 0) {
      uVar1 = FUN_006427ac(&PTR_DAT_006dae30);
    }
    else {
      uVar1 = (uint)(byte)*PTR_DAT_006dae30;
      PTR_DAT_006dae30 = PTR_DAT_006dae30 + 1;
    }
    if (uVar1 == 10) goto LAB_0063a9d0;
    if (uVar1 == 0xffffffff) break;
    *puVar2 = (char)uVar1;
    puVar2 = puVar2 + 1;
  }
  if (puVar2 == param_1) {
    param_1 = (undefined1 *)0x0;
  }
  else {
LAB_0063a9d0:
    *puVar2 = 0;
  }
  FUN_0063cf5e(0,&PTR_DAT_006dae30);
  return param_1;
}

