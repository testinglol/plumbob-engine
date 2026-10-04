
void FUN_005403b7(undefined1 *param_1,undefined1 *param_2)

{
  if (param_1 != (undefined1 *)0x0) {
    param_1[1] = param_2[1];
    *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_2 + 2);
    *(undefined2 *)(param_1 + 4) = *(undefined2 *)(param_2 + 4);
    *param_1 = *param_2;
  }
  return;
}

