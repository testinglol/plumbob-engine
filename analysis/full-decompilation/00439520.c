
void FUN_00439520(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    *(undefined1 *)(param_1 + 1) = *(undefined1 *)(param_2 + 1);
    *(undefined1 *)((int)param_1 + 5) = *(undefined1 *)((int)param_2 + 5);
    *(undefined1 *)((int)param_1 + 6) = *(undefined1 *)((int)param_2 + 6);
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
  }
  return;
}

