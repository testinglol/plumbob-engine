
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005f57e2(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float local_8;
  
  fVar1 = (_DAT_0067572c - _DAT_00675728) / ((float)param_1[0x40] - _DAT_00666748);
  fVar2 = _DAT_00675728 - fVar1;
  if ((char)param_1[0x3f] == '\0') {
    local_8 = (float)param_1[0x3b];
    *(undefined1 *)(param_1 + 0x3f) = 1;
  }
  else {
    fVar3 = (float10)FUN_00473496();
    local_8 = (float)fVar3;
  }
  fVar3 = (float10)FUN_00637fe4((double)(local_8 - (float)param_2));
  fVar3 = fVar3 * (float10)fVar1 + (float10)fVar2;
  if ((float10)_DAT_00675728 <= fVar3) {
    if ((float10)_DAT_0067572c < fVar3) {
      fVar3 = (float10)_DAT_0067572c;
    }
  }
  else {
    fVar3 = (float10)_DAT_00675728;
  }
  FUN_004734f9(local_8,(float)param_2,(float)(fVar3 * (float10)_DAT_00666b7c),DAT_006e5490);
  (**(code **)(*param_1 + 0x168))();
  return;
}

