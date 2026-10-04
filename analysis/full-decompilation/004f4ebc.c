
undefined4 __fastcall FUN_004f4ebc(int param_1)

{
  if (*(int *)(param_1 + 0x88) != 0) {
    (**(code **)(**(int **)(param_1 + 0x80) + 0x28))(*(int *)(param_1 + 0x88));
    *(undefined4 *)(param_1 + 0x88) = 0;
  }
  if (*(int *)(param_1 + 0x84) != 0) {
    (**(code **)(**(int **)(param_1 + 0x80) + 0x28))(*(int *)(param_1 + 0x84));
    *(undefined4 *)(param_1 + 0x84) = 0;
  }
  if (DAT_006feca8 != 0) {
    (**(code **)(**(int **)(param_1 + 0x80) + 0x28))(DAT_006feca8);
    DAT_006feca8 = 0;
  }
  if (DAT_006fecac != 0) {
    (**(code **)(**(int **)(param_1 + 0x80) + 0x28))(DAT_006fecac);
    DAT_006fecac = 0;
  }
  *(undefined4 *)(param_1 + 0x80) = 0;
  return 1;
}

