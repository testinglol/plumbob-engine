
int FUN_0063ca95(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_00703b48 = 1;
                    /* WARNING: Could not recover jumptable at 0x0063caaf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_00703b48 = 1;
                    /* WARNING: Could not recover jumptable at 0x0063cac4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_00703bfc;
  }
  DAT_00703b48 = (uint)bVar2;
  return param_1;
}

