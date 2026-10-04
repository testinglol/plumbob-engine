
void __fastcall FUN_004659d4(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_00667510;
  piVar2 = (int *)&DAT_006e5380;
  puVar1 = DAT_006e5380;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
    if (puVar1 == param_1) break;
    piVar2 = puVar1 + 1;
    puVar1 = (undefined4 *)puVar1[1];
  }
  *piVar2 = *(int *)(*piVar2 + 4);
  return;
}

