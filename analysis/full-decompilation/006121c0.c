
uint FUN_006121c0(double param_1,byte param_2,byte param_3)

{
  bool bVar1;
  uint uVar2;
  
  bVar1 = (double)param_3 < param_1;
  if (!bVar1) {
    bVar1 = (double)param_2 < param_1;
    param_3 = param_2;
    if ((double)param_2 <= param_1) {
      uVar2 = __ftol();
      return uVar2;
    }
  }
  return (uint)CONCAT11(bVar1,param_3);
}

