
undefined4 FUN_00404ccb(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_006de7f8;
  while( true ) {
    if (puVar1 == DAT_006de7fc) {
      return 0;
    }
    if (*(int *)*puVar1 == param_1) break;
    puVar1 = puVar1 + 1;
  }
  return *puVar1;
}

