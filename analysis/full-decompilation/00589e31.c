
undefined4 __fastcall FUN_00589e31(int param_1)

{
  if ((*(int *)(param_1 + 0x188) != 1) && (*(int *)(param_1 + 0x188) != -1)) {
    *(undefined4 *)(param_1 + 0x188) = 0;
    *(undefined4 *)(param_1 + 0x180) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x1c0) = 0;
    *(undefined4 *)(param_1 + 0x1c4) = *(undefined4 *)(param_1 + 0x80);
    *(undefined4 *)(param_1 + 0x1c8) = *(undefined4 *)(param_1 + 0x84);
    *(undefined4 *)(param_1 + 0x18c) = 1;
    *(undefined4 *)(param_1 + 0x1cc) = *(undefined4 *)(param_1 + 0x88);
    DAT_006f6d18 = 7;
    *(undefined4 *)(param_1 + 400) = 3;
    return 1;
  }
  *(undefined4 *)(param_1 + 0x284) = 1;
  return 0;
}

