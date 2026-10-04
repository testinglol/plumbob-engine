
undefined4 __fastcall FUN_0062bf4f(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_1 + 0x2484);
  iVar2 = *(int *)(param_1 + 0x2494) * 0x23280;
  *(undefined4 *)(param_1 + 0x4a20) = 1;
  *(int *)(param_1 + 0x4a24) = iVar2 / iVar1;
  *(int *)(param_1 + 0x4a28) = (iVar2 % iVar1) / 100;
  *(int *)(param_1 + 0x4a2c) = iVar1 / 100;
  iVar1 = *(int *)(param_1 + 0x4a40) * 0x900;
  *(int *)(param_1 + 0x248c) = iVar1;
  if ((*(char *)(param_1 + 0x2490) == '\x03') && (*(char *)(param_1 + 0x4a0e) != '\0')) {
    *(int *)(param_1 + 0x248c) = iVar1 >> 1;
  }
  *(undefined1 *)(param_1 + 0x4a0c) = 1;
  *(undefined4 *)(param_1 + 0x249c) = *(undefined4 *)(param_1 + 0x248c);
  if (*(char *)(param_1 + 0x2490) == '\x03') {
    *(undefined4 *)(param_1 + 0x4a08) = 0;
    *(undefined2 *)(param_1 + 0x4a06) = 0x240;
    *(undefined2 *)(param_1 + 0x4a04) = 0x240;
    *(char *)(param_1 + 0x4a10) = (*(char *)(param_1 + 0x4a0e) == '\0') + '\x01';
    FUN_0062cc32();
    puVar3 = (undefined4 *)(param_1 + 0x3804);
    for (iVar1 = 0x480; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
  }
  return 0;
}

