
void __thiscall FUN_004cfe14(int param_1,int param_2,char param_3)

{
  if ((*(int *)(param_1 + 0x230) != param_2) || (param_3 != '\0')) {
    if ((param_3 == '\0') && (param_2 == 0)) {
      FUN_0057a7f7(s_UI_whoosh_006c7b60,0xfffffffc);
    }
    *(byte *)(param_1 + 0xe) = *(byte *)(param_1 + 0xe) | 0x10;
    *(int *)(param_1 + 0x230) = param_2;
    if ((DAT_006f2a08 != 0) && (*(int *)(DAT_006f2a08 + 0x84) != 0)) {
      FUN_004d3dd8(param_2 == 1);
    }
  }
  return;
}

