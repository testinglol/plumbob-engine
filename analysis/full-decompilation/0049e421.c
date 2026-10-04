
void __thiscall FUN_0049e421(int *param_1,char param_2)

{
  DAT_006c6280 = DAT_006c628c;
  DAT_006c6284 = DAT_006c6290;
  DAT_006c6288 = DAT_006c6294;
  if (param_2 == '\0') {
    param_1[0x14] = 0x828c9b;
    param_1[0x15] = (int)&DAT_006e6e82;
  }
  else {
    param_1[0x14] = 0xe6f0ff;
    param_1[0x15] = 0xa1b4d2;
  }
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  *(undefined1 *)(param_1 + 0x23) = 0;
  *(undefined1 *)((int)param_1 + 0x8d) = 0;
  param_1[0x16] = 0x9d7541;
  param_1[0x17] = 0x513c12;
  param_1[0x31] = 0xfe242e;
  param_1[0x32] = 0x140000;
  (**(code **)(*param_1 + 0xc))();
  return;
}

