
undefined1 __fastcall FUN_005fbeed(int param_1)

{
  char cVar1;
  
  *(undefined4 *)(param_1 + 0xf08) = 0;
  *(undefined4 *)(param_1 + 0xf04) = 0xf00;
  *(undefined4 *)(param_1 + 0xf68) = *(undefined4 *)(param_1 + 0xf4c);
  cVar1 = FUN_005b8f4a(0x18);
  if (cVar1 == '\0') {
    *(undefined4 *)(param_1 + 0xf64) = 5;
    return 0;
  }
  return 1;
}

