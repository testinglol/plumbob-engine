
void FUN_005b8050(int param_1,uint param_2)

{
  (&DAT_006d24b0)[param_1 * 3] =
       ((&DAT_006d24b0)[param_1 * 3] ^ param_2) & 1 ^ (&DAT_006d24b0)[param_1 * 3];
  return;
}

