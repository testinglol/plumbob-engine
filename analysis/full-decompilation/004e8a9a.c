
undefined1 __fastcall FUN_004e8a9a(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)(param_1 + 0x10);
  iVar2 = 7;
  do {
    FUN_005a5e48(0);
    *puVar1 = 1;
    puVar1 = puVar1 + 8;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 1;
}

