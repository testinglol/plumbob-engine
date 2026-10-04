
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005447cb(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float local_8;
  
  fVar1 = (_DAT_0066f774 - _DAT_0066f770) / (_DAT_0066f778 - _DAT_00666748);
  fVar2 = _DAT_0066f770 - fVar1;
  if ((char)param_1[0x48] == '\0') {
    local_8 = (float)param_1[0x40];
    *(undefined1 *)(param_1 + 0x48) = 1;
  }
  else {
    fVar3 = (float10)FUN_00473496();
    local_8 = (float)fVar3;
  }
  fVar3 = (float10)FUN_00637fe4((double)(local_8 - (float)param_2));
  fVar3 = fVar3 * (float10)fVar1 + (float10)fVar2;
  if ((float10)_DAT_0066f770 <= fVar3) {
    if ((float10)_DAT_0066f774 < fVar3) {
      fVar3 = (float10)_DAT_0066f774;
    }
  }
  else {
    fVar3 = (float10)_DAT_0066f770;
  }
  FUN_004734f9(local_8,(float)param_2,(float)(fVar3 * (float10)_DAT_00666b7c),DAT_006e5490);
  (**(code **)(*param_1 + 0x168))();
  return;
}

