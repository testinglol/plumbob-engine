
void __fastcall FUN_00476c1e(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  *param_1 = &PTR_LAB_006678f0;
  puVar2 = &DAT_006e54b0;
  puVar1 = DAT_006e54b0;
  do {
    if (puVar1 == (undefined4 *)0x0) {
LAB_00476c43:
      param_1[1] = 0;
      return;
    }
    if (puVar1 == param_1) {
      *puVar2 = param_1[1];
      goto LAB_00476c43;
    }
    puVar2 = puVar1 + 1;
    puVar1 = (undefined4 *)puVar1[1];
  } while( true );
}

