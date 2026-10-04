
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00592a16(int *param_1,float param_2,char param_3)

{
  float10 fVar1;
  undefined4 uVar2;
  
  if ((float)param_1[0x38] < _DAT_0066657c) {
    param_3 = '\x01';
  }
  if ((float)_DAT_00671ec0 < ABS((float)param_1[0x38] - param_2)) {
    if (param_3 == '\0') {
      fVar1 = (float10)(**(code **)(*param_1 + 0xe4))();
      uVar2 = 0xfa;
    }
    else {
      uVar2 = 0xffffffff;
      fVar1 = (float10)param_2;
    }
    FUN_004734bd((float)fVar1,param_2,uVar2,DAT_006e5490);
    param_1[0x38] = (int)param_2;
  }
  return;
}

