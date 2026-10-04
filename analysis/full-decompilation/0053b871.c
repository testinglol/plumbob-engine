
void __thiscall FUN_0053b871(int param_1,int param_2)

{
  FUN_0053b90c(*(undefined4 *)(param_1 + 0x1e4));
  *(int *)(param_1 + 0x1e4) = param_2;
  if (param_2 == 1) {
    FUN_005e4320(1);
  }
  else {
    if (param_2 != 2) {
      if (param_2 != 3) {
        return;
      }
      if (*(char *)(param_1 + 0x1e0) != '\0') {
        return;
      }
      FUN_005dadff(param_1,500,0);
      *(undefined1 *)(param_1 + 0x1e0) = 1;
      return;
    }
    if (*(char *)(param_1 + 0x1e0) == '\0') {
      FUN_005dadff(param_1,500,0);
      *(undefined1 *)(param_1 + 0x1e0) = 1;
    }
  }
  FUN_005e46f0(1);
  return;
}

