
void FUN_005e0039(ushort *param_1)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  
  uVar1 = (uint)*param_1;
  if (uVar1 != DAT_006fe900) {
    puVar3 = param_1 + 1;
    do {
      if (uVar1 == DAT_006fe8fc) {
        return;
      }
      *param_1 = (ushort)DAT_006fe8fc;
      if (DAT_006fe908 <= (uint)((int)param_1 - DAT_006fe904)) {
        FUN_005e0039((int)param_1 - DAT_006fe904);
      }
      iVar2 = (int)(CONCAT44((int)((int)puVar3 - DAT_006fe908) >> 0x1f,
                             (int)((int)puVar3 - DAT_006fe908) >> 1) % (longlong)DAT_006fe910);
      if (iVar2 != 0) {
        FUN_005e0039(puVar3);
      }
      if ((uint)(DAT_006fe904 + (int)param_1) < DAT_006fe90c) {
        FUN_005e0039(DAT_006fe904 + (int)param_1);
      }
      if (iVar2 == 2) {
        return;
      }
      param_1 = param_1 + -1;
      puVar3 = puVar3 + -1;
      uVar1 = (uint)*param_1;
    } while (uVar1 != DAT_006fe900);
  }
  return;
}

