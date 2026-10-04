
undefined4 * FUN_004182c3(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = operator_new(0x14);
  puVar2 = (undefined4 *)*param_1;
  do {
    if (puVar2 == (undefined4 *)0x0) {
LAB_004182f7:
      puVar2 = operator_new(0x10);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = 0;
        puVar2[1] = param_2;
        puVar2[3] = 0;
      }
      if (puVar2 != (undefined4 *)0x0) {
        *puVar1 = 0;
        puVar2[2] = puVar1;
        *puVar2 = *param_1;
        *param_1 = puVar2;
      }
      return puVar1;
    }
    if (param_2 == puVar2[1]) {
      *puVar1 = puVar2[2];
      puVar2[2] = puVar1;
      if (puVar2 != (undefined4 *)0x0) {
        return puVar1;
      }
      goto LAB_004182f7;
    }
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}

