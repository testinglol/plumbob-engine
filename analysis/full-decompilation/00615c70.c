
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00615c70(int param_1,int param_2)

{
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38 [3];
  double local_20 [3];
  
  local_68 = (double)*(byte *)(param_1 + 1) * _DAT_00677580;
  local_60 = (double)*(byte *)(param_1 + 2) * _DAT_00677580;
  local_58 = (double)*(byte *)(param_1 + 3) * _DAT_00677580;
  FUN_00615d70(&local_68,local_20);
  local_50 = (double)*(byte *)(param_2 + 1) * _DAT_00677580;
  local_48 = (double)*(byte *)(param_2 + 2) * _DAT_00677580;
  local_40 = (double)*(byte *)(param_2 + 3) * _DAT_00677580;
  FUN_00615d70(&local_50,local_38);
  __ftol();
  return;
}

