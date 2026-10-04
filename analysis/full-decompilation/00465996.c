
undefined4 * __thiscall FUN_00465996(undefined4 *param_1,byte param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)&DAT_006e5380;
  *param_1 = &PTR_FUN_00667510;
  puVar1 = DAT_006e5380;
  do {
    if (puVar1 == (undefined4 *)0x0) {
LAB_004659c0:
      if ((param_2 & 1) != 0) {
        FUN_006321f0(param_1);
      }
      return param_1;
    }
    if (puVar1 == param_1) {
      *piVar2 = *(int *)(*piVar2 + 4);
      goto LAB_004659c0;
    }
    piVar2 = puVar1 + 1;
    puVar1 = (undefined4 *)puVar1[1];
  } while( true );
}

