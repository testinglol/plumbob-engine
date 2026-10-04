
void FUN_00619e00(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1 + 0x40;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = param_1;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)((int)param_1 + 0x2a) = 0xd;
  *(undefined1 *)((int)param_1 + 0x2f) = 0xd;
  *(undefined1 *)((int)param_1 + 0x25) = 0xd;
  *(undefined1 *)((int)param_1 + 0x2b) = 0xc;
  *(undefined1 *)((int)param_1 + 0x2d) = 0xc;
  *(undefined1 *)(param_1 + 0x21) = 9;
  *(undefined1 *)((int)param_1 + 0x85) = 9;
  *(undefined1 *)((int)param_1 + 0x3d) = 9;
  *(undefined1 *)((int)param_1 + 0x23) = 9;
  *(undefined1 *)((int)param_1 + 0x7e) = 7;
  *(undefined1 *)((int)param_1 + 0x5e) = 7;
  *(undefined1 *)(param_1 + 0x20) = 0xb;
  *(undefined1 *)((int)param_1 + 0x81) = 0xb;
  *(undefined1 *)(param_1 + 99) = 0xe;
  *(undefined1 *)((int)param_1 + 0x18d) = 0xe;
  *(undefined1 *)((int)param_1 + 0x18e) = 0xe;
  *(undefined1 *)((int)param_1 + 399) = 0xe;
  *(undefined1 *)(param_1 + 100) = 0xe;
  *(undefined1 *)((int)param_1 + 0x191) = 0xe;
  *(undefined1 *)((int)param_1 + 0x192) = 0xe;
  *(undefined1 *)((int)param_1 + 0x12a) = 0xe;
  *(undefined1 *)((int)param_1 + 299) = 0xe;
  *(undefined1 *)((int)param_1 + 0x12d) = 0xe;
  *(undefined1 *)((int)param_1 + 0x17e) = 0xe;
  *(undefined1 *)((int)param_1 + 0x21) = 6;
  *(undefined1 *)((int)param_1 + 0x121) = 0xe;
  *(undefined1 *)(param_1 + 0xf) = 10;
  *(undefined1 *)(param_1 + 0x4f) = 0xe;
  *(undefined1 *)((int)param_1 + 0x3e) = 10;
  *(undefined1 *)((int)param_1 + 0x13e) = 0xe;
  *(undefined1 *)((int)param_1 + 0x3f) = 3;
  *(undefined1 *)((int)param_1 + 0x3a) = 3;
  *(undefined1 *)((int)param_1 + 0x89) = 3;
  *(undefined1 *)((int)param_1 + 0x8a) = 3;
  *(undefined1 *)((int)param_1 + 0x29) = 2;
  *(undefined1 *)((int)param_1 + 0x5d) = 2;
  *(undefined1 *)(param_1 + 0xb) = 2;
  *(undefined1 *)((int)param_1 + 0x129) = 2;
  *(undefined1 *)((int)param_1 + 0x15d) = 2;
  *(undefined1 *)(param_1 + 0x4b) = 2;
  *(undefined1 *)(param_1 + 0x1f) = 6;
  *(undefined1 *)(param_1 + 10) = 1;
  *(undefined1 *)((int)param_1 + 0x5b) = 1;
  *(undefined1 *)((int)param_1 + 0x3b) = 1;
  *(undefined1 *)param_1 = 1;
  *(undefined1 *)((int)param_1 + 0x8b) = 0xf;
  *(undefined1 *)((int)param_1 + 0x82) = 10;
  *(undefined1 *)((int)param_1 + 0x83) = 10;
  *(undefined1 *)((int)param_1 + 0x26) = 8;
  *(undefined1 *)((int)param_1 + 0x86) = 5;
  *(undefined1 *)((int)param_1 + 0x87) = 4;
  *(undefined1 *)(param_1 + 0x22) = 4;
  *(undefined1 *)(param_1 + 0x4a) = 1;
  *(undefined1 *)((int)param_1 + 0x15b) = 1;
  *(undefined1 *)((int)param_1 + 0x13b) = 1;
  *(undefined1 *)(param_1 + 0x40) = 1;
  param_1[0x80] = 10;
  param_1[0x81] = 4;
  param_1[0x40ac] = 0;
  return;
}

