
void __fastcall FUN_004c9e0f(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = (undefined4 *)(param_1 + 0x10);
  do {
    puVar1[-3] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
    puVar1[7] = 0;
    puVar1[0xe] = 0;
    *(undefined1 *)(param_1 + 0x90 + iVar2) = 0;
    puVar1[0x1d] = 0;
    puVar1[0x17] = 0;
    puVar1[0x1a] = 0;
    iVar2 = iVar2 + 1;
    puVar1[0x11] = 0;
    puVar1[0x14] = 0;
    puVar1 = puVar1 + 1;
  } while (iVar2 < 3);
  *(undefined4 *)(param_1 + 0x38) = 0;
  return;
}

