
void __thiscall FUN_005254b4(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0xd8) == param_2) {
    *(undefined4 *)(param_1 + 0xd8) = 0;
    *(undefined1 *)(param_1 + 0xe6) = 0;
    FUN_005254ff(0);
    if (*(int *)(param_1 + 0xdc) != 0) {
      FUN_005dae65(param_1);
      *(undefined4 *)(param_1 + 0xdc) = 0;
    }
  }
  return;
}

