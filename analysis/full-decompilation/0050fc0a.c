
void __fastcall FUN_0050fc0a(int *param_1)

{
  if ((char)param_1[0x38] != '\0') {
    *(undefined1 *)(param_1 + 0x38) = 0;
    FUN_004734bd(0x3f800000,0,0xfa,DAT_006e5490);
    (**(code **)(*param_1 + 0x168))();
    FUN_0057a7f7(s_UI_whoosh_006c7b60,0xfffffffc);
    *(undefined1 *)(param_1 + 0x44) = 1;
  }
  return;
}

