
void __thiscall FUN_004e63f8(int param_1,char param_2)

{
  *(char *)(param_1 + 2) = param_2;
  if (param_2 == '\0') {
    DAT_006d7444 = 0x2ee;
    DAT_006d74f0 = 0x14d;
  }
  else {
    DAT_006d7444 = 0;
    DAT_006d74f0 = 0xfa;
  }
  return;
}

