
uint __fastcall FUN_004bb639(uint param_1,uint param_2,byte param_3)

{
  return ((param_1 & 0xf8) << 5 | param_2 & 0xf8) << 2 | (uint)(param_3 >> 3);
}

