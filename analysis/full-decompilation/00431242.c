
void __fastcall FUN_00431242(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_1[3] != 0) {
    FUN_006321f0(param_1[3]);
  }
  puVar1 = DAT_006e4a64;
  puVar3 = &DAT_006e4a64;
  do {
    puVar2 = puVar1;
    if (puVar2 == (undefined4 *)0x0) {
LAB_0043126f:
      param_1[3] = 0;
      param_1[7] = 0;
      param_1[1] = 0xffffffff;
      param_1[2] = 0xffffffff;
      FUN_00401729();
      return;
    }
    if (puVar2 == param_1) {
      *puVar3 = *param_1;
      goto LAB_0043126f;
    }
    puVar1 = (undefined4 *)*puVar2;
    puVar3 = puVar2;
  } while( true );
}

