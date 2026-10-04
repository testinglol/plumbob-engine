
ushort __fastcall FUN_004754d8(ushort *param_1)

{
  if (*param_1 == 0xffff) {
    return 0xffff;
  }
  return *param_1 & 0x7fff;
}

