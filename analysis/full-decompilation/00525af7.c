
undefined4 * __thiscall FUN_00525af7(undefined4 *param_1,int param_2)

{
  FUN_0050904a();
  *param_1 = &PTR_FUN_0066d074;
  param_1[0x35] = &PTR_LAB_0066d064;
  param_1[0x36] = param_2;
  param_1[0x37] = *(undefined4 *)(param_2 + 0x14);
  param_1[0x38] = *(undefined4 *)(param_2 + 0x18);
  param_1[0x39] = *(undefined4 *)(param_2 + 0x1c);
  param_1[0x3a] = *(undefined4 *)(param_2 + 0x20);
  *(undefined1 *)(param_1 + 0x3b) = 0;
  param_1[0x3c] = 0;
  *(undefined1 *)((int)param_1 + 0xed) = 1;
  return param_1;
}

