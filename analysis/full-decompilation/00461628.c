
void __thiscall FUN_00461628(byte *param_1,int param_2)

{
  if (0 < param_2) {
    *param_1 = (&DAT_006f4b20)[param_2 * 0x100 + (*param_1 & 0xf)] | *param_1 & 0xf0;
  }
  return;
}

