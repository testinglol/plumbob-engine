
void __fastcall FUN_00632b08(undefined4 *param_1)

{
  param_1[0xd] = 0xffffffff;
  *param_1 = &PTR_FUN_00689054;
  DAT_00703a98 = DAT_00703a98 + -1;
  if (DAT_00703a98 == 0) {
    FUN_00633e53(&DAT_00703a60);
  }
  FUN_00633e53(param_1 + 0xe);
  if ((param_1[7] != 0) && ((undefined4 *)param_1[1] != (undefined4 *)0x0)) {
    (*(code *)**(undefined4 **)param_1[1])(1);
  }
  param_1[1] = 0;
  param_1[2] = 4;
  return;
}

