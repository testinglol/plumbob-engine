
undefined4 __thiscall FUN_005d36f1(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    if (*(char *)(param_1 + 0xc0) == '\0') goto LAB_005d377f;
    FUN_005c6150();
    *(undefined4 *)(param_1 + 0xf8) = *(undefined4 *)(param_1 + 0xa8);
    *(undefined4 *)(param_1 + 0xfc) = *(undefined4 *)(param_1 + 0xac);
    *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(param_1 + 0xb0);
    *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(param_1 + 0xb4);
    *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_1 + 0xb8);
    *(undefined4 *)(param_1 + 0x10c) = *(undefined4 *)(param_1 + 0xbc);
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
  }
  else {
    *(undefined4 *)(param_1 + 0xf8) = *param_2;
    *(undefined4 *)(param_1 + 0xfc) = param_2[1];
    *(undefined4 *)(param_1 + 0x100) = param_2[2];
    *(undefined4 *)(param_1 + 0x104) = param_2[3];
    *(undefined4 *)(param_1 + 0x108) = param_2[4];
    *(undefined4 *)(param_1 + 0x10c) = param_2[5];
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
    *(undefined1 *)(param_1 + 0xc0) = 0;
  }
  *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xfffffffb;
LAB_005d377f:
  *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xfffffffe;
  return 0;
}

