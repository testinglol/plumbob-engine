
undefined4 __fastcall FUN_005d74d7(int param_1)

{
  *(undefined4 *)(param_1 + 0xd8) = 0;
  SetWindowLongA(DAT_006fe8cc,-0x10,-0x70000000);
  SetWindowPos(DAT_006fe8cc,(HWND)0x0,0,0,*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c),
               *(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80),0x37);
  return 1;
}

