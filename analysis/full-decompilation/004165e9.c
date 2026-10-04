
void __fastcall FUN_004165e9(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(param_1 + 0x38);
  iVar2 = 5;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[1] = DAT_006e4a28;
    *puVar1 = DAT_006e4a28;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  return;
}

