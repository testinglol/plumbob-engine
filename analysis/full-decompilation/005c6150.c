
undefined4 * __fastcall FUN_005c6150(int param_1)

{
  *(undefined4 *)(param_1 + 0x50) = 0x7e967699;
  *(undefined4 *)(param_1 + 0x4c) = 0x7e967699;
  *(undefined4 *)(param_1 + 0x48) = 0x7e967699;
  *(undefined4 *)(param_1 + 0x5c) = 0xfe967699;
  *(undefined4 *)(param_1 + 0x58) = 0xfe967699;
  *(undefined4 *)(param_1 + 0x54) = 0xfe967699;
  FUN_005c74c0((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc,0xc);
  *(undefined1 *)(param_1 + 0x60) = 0;
  return (undefined4 *)(param_1 + 0x48);
}

