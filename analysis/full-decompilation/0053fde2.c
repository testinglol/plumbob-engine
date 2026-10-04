
/* WARNING (jumptable): Unable to track spacebase fully for stack */

void FUN_0053fde2(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  puVar1 = *(undefined1 **)(unaff_EBP + 8);
  puVar2 = *(undefined1 **)(unaff_EBP + 0xc);
  *(undefined1 *)(extraout_ECX + 4) = *puVar1;
  *(undefined1 *)(extraout_ECX + 5) = puVar1[1];
  *(undefined1 *)(extraout_ECX + 6) = puVar1[2];
  *(undefined1 *)(extraout_ECX + 7) = *puVar2;
  *(undefined1 *)(extraout_ECX + 8) = puVar2[1];
  *(undefined1 *)(extraout_ECX + 9) = puVar2[2];
  iVar3 = FUN_0053f390((undefined1 *)(extraout_ECX + 4),(undefined1 *)(extraout_ECX + 7));
  *(int *)(extraout_ECX + 0x10) = iVar3;
  FUN_00461b74(&DAT_006e481c + iVar3 * 3);
  *(undefined1 *)(extraout_ECX + 10) = *(undefined1 *)(unaff_EBP + 8);
  *(undefined1 *)(extraout_ECX + 0xb) = *(undefined1 *)(unaff_EBP + 9);
  *(undefined1 *)(extraout_ECX + 0xc) = 0;
  *(undefined1 **)(extraout_ECX + 0x20) = puVar1;
  *(undefined1 **)(extraout_ECX + 0x24) = puVar2;
  *(int *)(puVar2 + 0x20) = *(int *)(puVar2 + 0x20) + 1;
  *(undefined4 *)(extraout_ECX + 0x14) = 0;
  switch(*(undefined4 *)(extraout_ECX + 0x10)) {
  case 0:
    *(undefined4 *)(extraout_ECX + 0x18) = 0;
    *(byte *)(extraout_ECX + 0x1c) = *(byte *)(extraout_ECX + 0x1c) | 1;
    *(byte *)(extraout_ECX + 0x1d) = *(byte *)(extraout_ECX + 0x1d) | 4;
    break;
  case 1:
    *(undefined4 *)(extraout_ECX + 0x18) = 1;
    *(byte *)(extraout_ECX + 0x1c) = *(byte *)(extraout_ECX + 0x1c) | 4;
    *(byte *)(extraout_ECX + 0x1d) = *(byte *)(extraout_ECX + 0x1d) | 1;
    break;
  case 2:
    *(undefined4 *)(extraout_ECX + 0x18) = 1;
    *(byte *)(extraout_ECX + 0x1c) = *(byte *)(extraout_ECX + 0x1c) | 2;
    *(byte *)(extraout_ECX + 0x1d) = *(byte *)(extraout_ECX + 0x1d) | 8;
    break;
  case 3:
    *(undefined4 *)(extraout_ECX + 0x18) = 0;
    *(byte *)(extraout_ECX + 0x1c) = *(byte *)(extraout_ECX + 0x1c) | 8;
    *(byte *)(extraout_ECX + 0x1d) = *(byte *)(extraout_ECX + 0x1d) | 2;
    break;
  case 4:
    *(undefined4 *)(extraout_ECX + 0x18) = 0;
    *(byte *)(extraout_ECX + 0x1c) = *(byte *)(extraout_ECX + 0x1c) | 0x10;
    *(byte *)(extraout_ECX + 0x1d) = *(byte *)(extraout_ECX + 0x1d) | 0x40;
    break;
  case 5:
    *(undefined4 *)(extraout_ECX + 0x18) = 0;
    *(byte *)(extraout_ECX + 0x1c) = *(byte *)(extraout_ECX + 0x1c) | 0x40;
    *(byte *)(extraout_ECX + 0x1d) = *(byte *)(extraout_ECX + 0x1d) | 0x10;
    break;
  case 6:
    *(undefined4 *)(extraout_ECX + 0x18) = 0;
    *(byte *)(extraout_ECX + 0x1c) = *(byte *)(extraout_ECX + 0x1c) | 0x80;
    *(byte *)(extraout_ECX + 0x1d) = *(byte *)(extraout_ECX + 0x1d) | 0x20;
    break;
  case 7:
    *(undefined4 *)(extraout_ECX + 0x18) = 1;
    *(byte *)(extraout_ECX + 0x1c) = *(byte *)(extraout_ECX + 0x1c) | 0x20;
    *(byte *)(extraout_ECX + 0x1d) = *(byte *)(extraout_ECX + 0x1d) | 0x80;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined2 *)(unaff_EBP + -0x12) = 0;
  *(undefined2 *)(unaff_EBP + -0x10) = 0;
  *(undefined1 *)(unaff_EBP + -0x14) = 0;
  *(undefined1 *)(unaff_EBP + -0x13) = 1;
  FUN_0053ffb2(unaff_EBP + -0x14);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

