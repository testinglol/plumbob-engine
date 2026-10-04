
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00615380(byte *param_1,byte *param_2)

{
  int iVar1;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  local_38 = (double)param_1[2] * _DAT_00677580;
  local_30 = (double)param_1[1] * _DAT_00677580;
  local_28 = (double)*param_1 * _DAT_00677580;
  FUN_00623e80(&local_38,&local_68);
  local_20 = (double)param_2[2] * _DAT_00677580;
  local_18 = (double)param_2[1] * _DAT_00677580;
  local_10 = (double)*param_2 * _DAT_00677580;
  FUN_00623e80(&local_20,&local_50);
  local_68 = local_68 * _DAT_00677778;
  local_60 = local_60 * _DAT_00666740;
  local_58 = local_58 * _DAT_00666740;
  local_50 = local_50 * _DAT_00677778;
  local_48 = local_48 * _DAT_00666740;
  local_40 = local_40 * _DAT_00666740;
  iVar1 = FUN_00615560(local_68,local_50,DAT_006da264,DAT_006da258);
  if ((((iVar1 == 0) || (local_60 < (double)_DAT_006da268 + local_48)) ||
      ((double)_DAT_006da25c + local_48 < local_60)) ||
     ((local_58 < (double)_DAT_006da26c + local_40 || ((double)_DAT_006da260 + local_40 < local_58))
     )) {
    return 0;
  }
  if (((local_68 == local_50) && (local_60 == local_48)) && (local_58 == local_40)) {
    return 1;
  }
  return 1;
}

