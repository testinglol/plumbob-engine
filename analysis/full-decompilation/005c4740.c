
void __fastcall FUN_005c4740(undefined4 *param_1)

{
  if ((undefined1 *)*param_1 != (undefined1 *)param_1[1]) {
    *(undefined1 *)*param_1 = 0;
    param_1[1] = *param_1;
  }
  return;
}

