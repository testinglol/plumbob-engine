
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e81eb(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  float fVar2;
  
  fVar2 = (float)param_5 * _DAT_00667420;
  if (_DAT_0066657c <= fVar2) {
    if (_DAT_00666748 < fVar2) {
      fVar2 = 1.0;
    }
  }
  else {
    fVar2 = 0.0;
  }
  (**(code **)(*param_1 + 0x8c))(param_2,param_3,param_4,fVar2);
  uVar1 = FUN_00592e1e(param_2,param_3,param_4,fVar2);
  FUN_005a5e48(uVar1);
  FUN_005a5e72();
  return;
}

