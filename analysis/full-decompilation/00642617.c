
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00642617(int param_1,int param_2,double param_3,double *param_4)

{
  double dVar1;
  double dVar2;
  int iVar3;
  
  dVar1 = (double)CONCAT44(param_2,param_1);
  if ((double)CONCAT44(param_2,param_1) < _DAT_006669e8) {
    dVar1 = -dVar1;
  }
  dVar2 = _DAT_006dd478;
  if (param_3._4_4_ == 0x7ff00000) {
    if (param_3._0_4_ != 0) {
LAB_006426a2:
      if (param_2 == 0x7ff00000) {
        if (param_1 != 0) {
          return 0;
        }
        if (_DAT_006669e8 < param_3) goto LAB_0064273d;
        if (param_3 < _DAT_006669e8) goto LAB_006426d4;
      }
      else {
        if (param_2 != -0x100000) {
          return 0;
        }
        if (param_1 != 0) {
          return 0;
        }
        iVar3 = FUN_00642747(param_3);
        if (_DAT_006669e8 < param_3) {
          dVar2 = _DAT_006dd478;
          if (iVar3 == 1) {
            dVar2 = -_DAT_006dd478;
          }
          goto LAB_0064273d;
        }
        if (param_3 < _DAT_006669e8) {
          dVar2 = _DAT_006dd498;
          if (iVar3 != 1) {
            dVar2 = 0.0;
          }
          goto LAB_0064273d;
        }
      }
      dVar2 = 1.0;
      goto LAB_0064273d;
    }
    if (_DAT_00667280 < dVar1) goto LAB_0064273d;
    if (_DAT_00667280 <= dVar1) {
LAB_00642667:
      *param_4 = _DAT_006dd480;
      return 1;
    }
  }
  else {
    if ((param_3._4_4_ != -0x100000) || (param_3._0_4_ != 0)) goto LAB_006426a2;
    if (dVar1 <= _DAT_00667280) {
      if (_DAT_00667280 <= dVar1) goto LAB_00642667;
      goto LAB_0064273d;
    }
  }
LAB_006426d4:
  dVar2 = 0.0;
LAB_0064273d:
  *param_4 = dVar2;
  return 0;
}

