
void FUN_005b7f80(void)

{
  undefined4 *puVar1;
  int in_stack_00002004;
  
  FUN_00636080();
  if (DAT_006fd8ec == 0) {
    FUN_005b7ed0();
  }
  if ((*(byte *)(&DAT_006d229c + in_stack_00002004 * 2) & 1) != 0) {
    FUN_006385fa();
    puVar1 = &DAT_006d24ac;
    do {
      if (((*(byte *)(puVar1 + 1) & 1) != 0) && ((code *)*puVar1 != (code *)0x0)) {
        (*(code *)*puVar1)();
      }
      puVar1 = puVar1 + 3;
    } while ((int)puVar1 < 0x6d250c);
  }
  return;
}

