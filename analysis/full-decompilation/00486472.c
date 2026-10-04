
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00486472(int param_1)

{
  int *piVar1;
  int *piVar2;
  int local_c;
  int local_8;
  
  local_c = param_1;
  local_8 = param_1;
  if (DAT_006c5e40 != -1) {
    local_8 = 0;
    local_c = 0;
    piVar2 = &local_c;
    piVar1 = &local_8;
    (**(code **)(*DAT_006fe8bc + 0x18))(piVar1,piVar2);
    FUN_005d9928(piVar1,piVar2);
    if (0x10 < (local_c - _DAT_006c5e44) * (local_c - _DAT_006c5e44) +
               (local_8 - DAT_006c5e40) * (local_8 - DAT_006c5e40)) {
      DAT_006c5e40 = -1;
    }
    if (DAT_006c5e40 != -1) {
      return;
    }
  }
  FUN_004d2900(0);
  DAT_006c5e40 = 0xffffffff;
  return;
}

