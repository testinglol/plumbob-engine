
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063cb12(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00705240;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_00705124 = 0;
  DAT_0070513c = 0;
  DAT_00705344 = 0;
  _DAT_00705130 = 0;
  DAT_00705134 = 0;
  _DAT_00705138 = 0;
  return;
}

