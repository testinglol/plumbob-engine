
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00513a51(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  float10 fVar3;
  
  fVar3 = (float10)FUN_00513ade();
  uVar2 = FUN_00513857(0x405d5f,0xd10000,(float)fVar3);
  FUN_0050c54c(uVar2,uVar2,0);
  fVar1 = (float)(*(int *)(param_1 + 0x194) + 0x32) * _DAT_00667420;
  if (_DAT_0066657c <= fVar1) {
    if (_DAT_00666748 < fVar1) {
      fVar1 = 1.0;
    }
  }
  else {
    fVar1 = 0.0;
  }
  uVar2 = FUN_00513857(0x405d5f,0xca39,fVar1);
  FUN_0050c54c(uVar2,uVar2,0);
  return;
}

