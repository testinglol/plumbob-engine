
undefined1 * FUN_00639e4d(undefined1 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  FUN_0063d88b(3);
  if (DAT_00703b20 != '\0') goto LAB_00639e7b;
  init_namebuf(0);
  do {
    iVar1 = FUN_00639cdd(&DAT_00703b20,0);
    if (iVar1 != 0) {
      if (param_1 == (undefined1 *)0x0) {
        iVar1 = FUN_0063e1d3();
        if (*(int *)(iVar1 + 0x28) == 0) {
          pvVar2 = _malloc(0xe);
          *(void **)(iVar1 + 0x28) = pvVar2;
          if (pvVar2 == (void *)0x0) {
            param_1 = &DAT_00703b20;
            goto LAB_00639ebd;
          }
        }
        param_1 = *(undefined1 **)(iVar1 + 0x28);
      }
      FUN_006358b0(param_1,&DAT_00703b20);
      goto LAB_00639ebd;
    }
LAB_00639e7b:
    iVar1 = FUN_00639f2c(&DAT_00703b20);
  } while (iVar1 == 0);
  param_1 = (undefined1 *)0x0;
LAB_00639ebd:
  FUN_0063d8ec(3);
  return param_1;
}

