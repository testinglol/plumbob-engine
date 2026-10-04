
void __thiscall FUN_005ecd57(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x94) = 0;
    *(undefined1 *)(param_1 + 0x91) = 0;
  }
  else {
    *(int *)(param_1 + 0x94) = param_2;
    *(undefined1 *)(param_1 + 0x91) = 1;
  }
  return;
}

