
void FUN_00540424(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 6) {
    if (param_3 != (undefined1 *)0x0) {
      param_3[1] = param_1[1];
      *(undefined2 *)(param_3 + 2) = *(undefined2 *)(param_1 + 2);
      *(undefined2 *)(param_3 + 4) = *(undefined2 *)(param_1 + 4);
      *param_3 = *param_1;
    }
    param_3 = param_3 + 6;
  }
  return;
}

