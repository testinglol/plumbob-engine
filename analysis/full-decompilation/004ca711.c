
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ca711(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  
  puVar2 = &DAT_006f0c60;
  do {
    uVar1 = __ftol();
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
  } while ((int)puVar2 < 0x6f0e5e);
  return;
}

