
void FUN_005e012c(ushort *param_1)

{
  uint uVar1;
  ushort *puVar2;
  
  uVar1 = (uint)*param_1;
  if (uVar1 != DAT_006fe900) {
    puVar2 = param_1 + -1;
    do {
      if (uVar1 == DAT_006fe8fc) {
        return;
      }
      *param_1 = (ushort)DAT_006fe8fc;
      FUN_005e012c((int)param_1 - DAT_006fe904);
      FUN_005e012c(DAT_006fe904 + (int)param_1);
      FUN_005e012c(puVar2);
      param_1 = param_1 + 1;
      puVar2 = puVar2 + 1;
      uVar1 = (uint)*param_1;
    } while (uVar1 != DAT_006fe900);
  }
  return;
}

