
void FUN_004c2ca6(byte *param_1,undefined2 *param_2)

{
  *param_2 = *(undefined2 *)(DAT_006f0a78 + (uint)*param_1 * 2);
  param_2[1] = *(undefined2 *)(DAT_006f0a78 + (uint)param_1[1] * 2);
  param_2[2] = *(undefined2 *)(DAT_006f0a78 + (uint)param_1[2] * 2);
  param_2[3] = *(undefined2 *)(DAT_006f0a78 + (uint)param_1[3] * 2);
  return;
}

