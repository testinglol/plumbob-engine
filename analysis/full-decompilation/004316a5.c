
undefined4 * FUN_004316a5(undefined4 param_1)

{
  char cVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_006e4a64;
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    cVar1 = FUN_004317d5(puVar2 + 4,param_1);
    if (cVar1 != '\0') break;
    puVar2 = (undefined4 *)*puVar2;
  }
  return puVar2;
}

