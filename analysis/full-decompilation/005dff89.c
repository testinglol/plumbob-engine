
void FUN_005dff89(ushort *param_1)

{
  ushort *puVar1;
  
  if (*param_1 == DAT_006fe900) {
    puVar1 = param_1 + -1;
    do {
      *param_1 = (ushort)DAT_006fe8fc;
      FUN_005dff89((int)param_1 - DAT_006fe904);
      FUN_005dff89(DAT_006fe904 + (int)param_1);
      FUN_005dff89(puVar1);
      param_1 = param_1 + 1;
      puVar1 = puVar1 + 1;
    } while (*param_1 == DAT_006fe900);
  }
  return;
}

