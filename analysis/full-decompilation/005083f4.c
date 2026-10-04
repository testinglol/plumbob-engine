
void __thiscall FUN_005083f4(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  
  *(undefined1 *)(param_1 + 0xf0) = 1;
  *(undefined4 *)(param_1 + 0x11c) = param_3;
  FUN_005083af(param_2);
  cVar1 = (**(code **)(**(int **)(DAT_006f2a08 + 0x84) + 0x38))(param_1);
  if (cVar1 == '\0') {
    (**(code **)(**(int **)(DAT_006f2a08 + 0x84) + 0x20))(param_1);
    FUN_005ddfdc(1);
    FUN_0057a7f7(s_UI_whoosh_006c7b60,0xfffffffc);
    FUN_004734bd(0,(float)(*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80)),0xfa,DAT_006e5490);
  }
  return;
}

