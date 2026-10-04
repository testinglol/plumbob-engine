
undefined4 __thiscall FUN_005e4071(int param_1,undefined4 param_2)

{
  if ((*(char *)(param_1 + 0x16a) != '\0') && (*(int **)(param_1 + 0x14c) != (int *)0x0)) {
    (**(code **)(**(int **)(param_1 + 0x14c) + 8))(1);
  }
  *(undefined1 *)(param_1 + 0x16a) = 0;
  *(undefined4 *)(param_1 + 0x14c) = param_2;
  return 1;
}

